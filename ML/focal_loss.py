import torch
import torch.nn as nn
import torch.nn.functional as F


class FocalLoss(nn.Module):
    def __init__(self, alpha=1, gamma=2, reduction="mean"):
        super(FocalLoss, self).__init__()
        self.alpha = alpha
        self.gamma = gamma
        self.reduction = reduction

    def forward(self, inputs, targets):
        # 将输入经过softmax
        inputs = F.softmax(inputs, dim=-1)

        # 选择正确类别的概率
        pt = inputs.gather(1, targets.unsqueeze(1)).squeeze(1)

        # 计算Focal Loss
        loss = -self.alpha * (1 - pt) ** self.gamma * torch.log(pt)

        # 根据 reduction 选项返回损失
        if self.reduction == "mean":
            return loss.mean()
        elif self.reduction == "sum":
            return loss.sum()
        else:
            return loss


# 示例使用
if __name__ == "__main__":
    # 假设有3个类别
    inputs = torch.tensor([[1.5, 0.3, 0.2], [0.1, 2.0, 0.1], [0.05, 0.1, 3.0]])
    targets = torch.tensor([0, 1, 2])  # 真实类别标签

    focal_loss = FocalLoss(alpha=1, gamma=2, reduction="mean")
    loss = focal_loss(inputs, targets)

    print(f"Focal Loss: {loss.item()}")
