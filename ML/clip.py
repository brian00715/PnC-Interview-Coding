import torch
import torch.nn as nn
import torch.nn.functional as F
from torchvision import models

class CLIPModel(nn.Module):
    def __init__(self, embed_dim, image_model='resnet50', text_vocab_size=10000, text_seq_len=77, text_embed_dim=512):
        super(CLIPModel, self).__init__()

        # 图像编码器
        self.image_encoder = models.__dict__[image_model](pretrained=True)
        self.image_encoder.fc = nn.Linear(self.image_encoder.fc.in_features, embed_dim)

        # 文本编码器
        self.text_embedding = nn.Embedding(text_vocab_size, text_embed_dim)
        self.text_encoder = nn.Transformer(
            d_model=text_embed_dim, 
            nhead=8, 
            num_encoder_layers=6, 
            dim_feedforward=2048
        )
        self.text_projection = nn.Linear(text_embed_dim, embed_dim)

        # 温度参数
        self.logit_scale = nn.Parameter(torch.ones([]) * torch.log(torch.tensor(1 / 0.07)))

    def forward(self, images, texts):
        # 图像编码
        image_features = self.image_encoder(images)  # [batch_size, embed_dim]

        # 文本编码
        text_features = self.text_embedding(texts)  # [batch_size, seq_len, text_embed_dim]
        text_features = self.text_encoder(text_features.permute(1, 0, 2))  # 交换维度以适配 Transformer
        text_features = text_features.mean(dim=0)  # 聚合序列信息
        text_features = self.text_projection(text_features)  # 投射到图像嵌入空间

        # 归一化
        image_features = F.normalize(image_features, p=2, dim=-1)
        text_features = F.normalize(text_features, p=2, dim=-1)

        # 计算对比学习损失
        logit_scale = self.logit_scale.exp()
        logits_per_image = logit_scale * image_features @ text_features.t()
        logits_per_text = logits_per_image.t()

        return logits_per_image, logits_per_text

def clip_loss(logits_per_image, logits_per_text):
    batch_size = logits_per_image.size(0)
    labels = torch.arange(batch_size, device=logits_per_image.device)

    loss_image = F.cross_entropy(logits_per_image, labels)
    loss_text = F.cross_entropy(logits_per_text, labels)

    return (loss_image + loss_text) / 2

# 示例使用
if __name__ == "__main__":
    # 示例参数
    batch_size = 8
    embed_dim = 512
    text_vocab_size = 10000
    text_seq_len = 77

    # 模拟输入
    images = torch.randn(batch_size, 3, 224, 224)
    texts = torch.randint(0, text_vocab_size, (batch_size, text_seq_len))

    # 初始化模型
    model = CLIPModel(embed_dim=embed_dim, text_vocab_size=text_vocab_size, text_seq_len=text_seq_len)

    # 前向传播
    logits_per_image, logits_per_text = model(images, texts)

    # 计算损失
    loss = clip_loss(logits_per_image, logits_per_text)
    print(f"CLIP Loss: {loss.item()}")
