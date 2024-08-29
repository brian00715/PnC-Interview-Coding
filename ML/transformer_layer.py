import torch
import torch.nn as nn
import torch.nn.functional as F

class MultiHeadSelfAttention(nn.Module):
    def __init__(self, embed_dim, num_heads):
        super(MultiHeadSelfAttention, self).__init__()
        assert embed_dim % num_heads == 0, "Embedding dimension must be divisible by number of heads"

        self.num_heads = num_heads
        self.head_dim = embed_dim // num_heads

        self.qkv = nn.Linear(embed_dim, embed_dim * 3)
        self.fc_out = nn.Linear(embed_dim, embed_dim)

    def forward(self, x):
        batch_size, seq_length, embed_dim = x.size()

        # Compute query, key, and value matrices
        qkv = self.qkv(x)  # [batch_size, seq_length, 3 * embed_dim]
        qkv = qkv.reshape(batch_size, seq_length, 3, self.num_heads, self.head_dim)
        qkv = qkv.permute(2, 0, 3, 1, 4)  # [3, batch_size, num_heads, seq_length, head_dim]
        q, k, v = qkv[0], qkv[1], qkv[2]  # Queries, Keys, and Values

        # Scaled Dot-Product Attention
        energy = torch.einsum("bhqd, bhkd -> bhqk", q, k)  # [batch_size, num_heads, seq_length, seq_length]
        scale = torch.sqrt(torch.tensor(self.head_dim, dtype=torch.float32)).to(energy.device)
        attention = F.softmax(energy / scale, dim=-1)  # Attention weights

        out = torch.einsum("bhqk, bhvd -> bhqd", attention, v)  # [batch_size, num_heads, seq_length, head_dim]
        out = out.permute(0, 2, 1, 3).reshape(batch_size, seq_length, embed_dim)  # Concatenate heads

        # Final linear layer
        out = self.fc_out(out)  # [batch_size, seq_length, embed_dim]
        return out

class TransformerLayer(nn.Module):
    def __init__(self, embed_dim, num_heads, ff_hidden_dim, dropout=0.1):
        super(TransformerLayer, self).__init__()
        self.self_attention = MultiHeadSelfAttention(embed_dim, num_heads)
        self.layernorm1 = nn.LayerNorm(embed_dim)
        self.ffn = nn.Sequential(
            nn.Linear(embed_dim, ff_hidden_dim),
            nn.ReLU(),
            nn.Linear(ff_hidden_dim, embed_dim)
        )
        self.layernorm2 = nn.LayerNorm(embed_dim)
        self.dropout = nn.Dropout(dropout)

    def forward(self, x):
        # Self-attention + residual connection + layer normalization
        attention_out = self.self_attention(x)
        x = self.layernorm1(x + self.dropout(attention_out))

        # Feedforward network + residual connection + layer normalization
        ffn_out = self.ffn(x)
        x = self.layernorm2(x + self.dropout(ffn_out))

        return x

# 示例使用
if __name__ == "__main__":
    batch_size = 32
    seq_length = 10
    embed_dim = 512
    num_heads = 8
    ff_hidden_dim = 2048

    # 模拟输入
    x = torch.randn(batch_size, seq_length, embed_dim)

    # 初始化 Transformer Layer
    transformer_layer = TransformerLayer(embed_dim, num_heads, ff_hidden_dim)

    # 前向传播
    out = transformer_layer(x)
    print(out.shape)  # 输出形状应为 (batch_size, seq_length, embed_dim)
