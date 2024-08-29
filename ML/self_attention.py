"""
refer to https://blog.51cto.com/u_14300986/5467376
"""

import numpy as np

d = 128  # dimention
n = 32  # number of tokens
Wq = np.random.randn(d, d)
Wk = np.random.randn(d, d)
Wv = np.random.randn(d, d)

x = np.random.randn(d, n)

q = Wq @ x
k = Wk @ x
v = Wv @ x
print(f"q_shape:{q.shape}, k_shape:{k.shape}, v_shape:{v.shape}")

A = q @ k.T
A /= np.sqrt(d)


def softmax(A):
    ex = np.exp(A - np.max(A))
    return ex / ex.sum(axis=0)


A_hat = softmax(A)
output = A_hat @ v
print(f"output_shape:{output.shape}")

import torch
import torch.nn as nn


class SelfAttention(nn.module):
    def __init__(self, input_dim, k_dim, v_dim):
        super(SelfAttention, self).__init__()
        self.Wq = nn.Linear(input_dim, k_dim)
        self.Wk = nn.Linear(input_dim, k_dim)
        self.Wv = nn.Linear(input_dim, v_dim)
        self.norm_factor = np.sqrt(k_dim)

    def forward(self, x):
        q = self.Wq(x)
        k = self.Wk(x)
        v = self.Wv(x)

        atten = (
            nn.Softmax(dim=-1)(torch.bmm(q, k.permute(0, 2, 1))) * self.norm_factor
        )  # Q * K.T() # batch_size * seq_len * seq_len

        output = torch.bmm(atten, v)  # Q * K.T() * V # batch_size * seq_len * dim_v
