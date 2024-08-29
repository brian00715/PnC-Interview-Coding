import torch
import torch.nn as nn
import numpy as np


"""手撕多头自注意力"""


class MultiHeadAttention(nn.Module):
    def __init__(self, input_dim, heads, d_model, dropout=0.1):
        super(MultiHeadAttention, self).__init__()
        self.d_model = d_model
        self.heads = heads
        self.input_dim = input_dim
        self.d_k = d_model // heads

        self.linear_q = nn.Linear(self.input_dim, self.d_model)
        self.linear_k = nn.Linear(self.input_dim, self.d_model)
        self.linear_v = nn.Linear(self.input_dim, self.d_model)

        self.dropout = nn.Dropout(dropout)
        self.fact = 1 / np.sqrt(self.d_k)

        self.out = nn.Linear(d_model, d_model)

    def forward(self, x, mask=None):
        batch_size, seq_len, hidden_size = x.shape
        q = self.linear_q(x).view(batch_size, -1, self.heads, self.d_k)
        k = self.linear_k(x).view(batch_size, -1, self.heads, self.d_k)
        v = self.linear_v(x).view(batch_size, -1, self.heads, self.d_k)

        q = q.transpose(1, 2)
        k = k.transpose(1, 2)
        v = v.transpose(1, 2)  # batch,head,seq_len,d_k

        # 求注意力
        score = torch.matmul(q, k.transpose(-2, -1)) * self.fact
        if mask is not None:
            score = score + mask

        att = torch.softmax(score, dim=-1)
        if self.dropout is not None:
            att = self.dropout(att)
        output = torch.matmul(att, v)  # (batch,head,sel_len,d_k)

        # 拼接
        concat = output.transpose(1, 2).contiguous().view(batch_size, -1, self.d_model)

        output = self.out(concat)
        return output


if __name__ == "__main__":
    pass
    batch = 2
    seq_len = 5
    input_dim = 32
    head = 2
    d_model = 32
    x = torch.randn(size=(batch, seq_len, input_dim))
    attention = MultiHeadAttention(input_dim, head, d_model)
    print(attention(x).shape)
    # 求掩码
    attention_mask = torch.tril(torch.ones(size=(seq_len, seq_len), dtype=torch.bool)).view(1, 1, seq_len, seq_len)
    attention_mask = attention_mask.to(dtype=torch.float16)
    attention_mask = (1.0 - attention_mask) * torch.finfo(torch.float16).min
    print(attention_mask)
    print(attention(x).shape)
