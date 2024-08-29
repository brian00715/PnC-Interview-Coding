import torch
import torch.nn as nn
import torch.nn.functional as F


class DeformableConv2d(nn.Module):
    def __init__(self, in_channels, out_channels, kernel_size, stride=1, padding=0, dilation=1, groups=1, bias=True):
        super(DeformableConv2d, self).__init__()
        self.stride = stride
        self.padding = padding
        self.dilation = dilation
        self.kernel_size = kernel_size

        self.offset_conv = nn.Conv2d(
            in_channels,
            2 * kernel_size * kernel_size,
            kernel_size=kernel_size,
            stride=stride,
            padding=padding,
            dilation=dilation,
            groups=groups,
            bias=bias,
        )
        self.conv = nn.Conv2d(
            in_channels,
            out_channels,
            kernel_size=kernel_size,
            stride=stride,
            padding=padding,
            dilation=dilation,
            groups=groups,
            bias=bias,
        )

    def forward(self, x):
        offset = self.offset_conv(x)
        N, _, H, W = offset.shape
        p = self._get_p(offset, H, W)
        x_offset = self._get_x_offset(x, p)
        out = self.conv(x_offset)
        return out

    def _get_p(self, offset, H, W):
        # Generate the meshgrid for the standard convolutional coordinates
        p_h, p_w = torch.meshgrid(
            torch.arange(0, self.kernel_size, dtype=torch.float32, device=offset.device),
            torch.arange(0, self.kernel_size, dtype=torch.float32, device=offset.device),
        )
        p_h = p_h.flatten().repeat(H * W).view(1, 1, -1)
        p_w = p_w.flatten().repeat(H * W).view(1, 1, -1)
        p_base = torch.cat((p_h, p_w), dim=1).view(1, 2 * self.kernel_size * self.kernel_size, H, W)
        return offset + p_base

    def _get_x_offset(self, x, p):
        N, C, H, W = x.shape
        p = p.permute(0, 2, 3, 1).contiguous()
        p = p.view(N, H, W, self.kernel_size * self.kernel_size, 2)
        p_h = p[:, :, :, :, 0].unsqueeze(1).repeat(1, C, 1, 1, 1)
        p_w = p[:, :, :, :, 1].unsqueeze(1).repeat(1, C, 1, 1, 1)

        # Interpolation
        p_h_floor = torch.floor(p_h).long()
        p_w_floor = torch.floor(p_w).long()
        p_h_ceil = p_h_floor + 1
        p_w_ceil = p_w_floor + 1

        # Clipping
        p_h_floor = p_h_floor.clamp(0, H - 1)
        p_w_floor = p_w_floor.clamp(0, W - 1)
        p_h_ceil = p_h_ceil.clamp(0, H - 1)
        p_w_ceil = p_w_ceil.clamp(0, W - 1)

        # Gather 4 surrounding points
        x_offset = (
            (p_h_ceil.float() - p_h) * (p_w_ceil.float() - p_w) * self._gather_feature(x, p_h_floor, p_w_floor)
            + (p_h_ceil.float() - p_h) * (p_w - p_w_floor.float()) * self._gather_feature(x, p_h_floor, p_w_ceil)
            + (p_h - p_h_floor.float()) * (p_w_ceil.float() - p_w) * self._gather_feature(x, p_h_ceil, p_w_floor)
            + (p_h - p_h_floor.float()) * (p_w - p_w_floor.float()) * self._gather_feature(x, p_h_ceil, p_w_ceil)
        )

        return x_offset

    def _gather_feature(self, x, p_h, p_w):
        N, C, H, W = x.shape
        p_h = p_h.clamp(0, H - 1)
        p_w = p_w.clamp(0, W - 1)
        return x[:, :, p_h, p_w].permute(0, 2, 1, 3, 4).contiguous()


# 示例用法
x = torch.randn(1, 3, 64, 64)  # 输入张量 (N, C, H, W)
deform_conv = DeformableConv2d(3, 64, kernel_size=3, padding=1)
out = deform_conv(x)
print(out.shape)
