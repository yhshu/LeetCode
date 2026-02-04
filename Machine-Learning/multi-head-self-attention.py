import math
import torch
import torch.nn as nn
import torch.nn.functional as F


class MultiHeadSelfAttention(nn.Module):
    def __init__(self, model_dim, num_heads, dropout=0.0):
        super().__init__()
        if model_dim % num_heads != 0:
            raise ValueError("model_dim must be divisible by num_heads")

        self.model_dim = model_dim
        self.num_heads = num_heads
        self.head_dim = model_dim // num_heads # Dimension per head

        # Project input into Q, K, V in one go:
        # (batch_size, seq_len, model_dim) -> (batch_size, seq_len, 3 * model_dim)
        self.w_qkv = nn.Linear(model_dim, 3 * model_dim, bias=True)

        # Output projection to mix heads back into model_dim
        self.w_o = nn.Linear(model_dim, model_dim, bias=True)

        self.dropout = nn.Dropout(dropout)

    def forward(self, x, mask=None):
        """
        x: (batch_size, seq_len, model_dim)
        mask: optional, broadcastable to (batch_size, num_heads, seq_len, seq_len), use 1 for keep and 0 for mask. The two seq_len dimensions mean: for each query position (row), choose which key positions (columns) it is allowed to attend to.
        """
        batch_size, seq_len, _ = x.shape

        # 1) Linear projection for Q, K, V
        qkv = self.w_qkv(x)  # (batch_size, seq_len, 3 * model_dim)

        # 2) Split into Q, K, V and heads
        # (batch_size, seq_len, 3 * model_dim)
        # split dimensions by head -> (batch_size, seq_len, 3, num_heads, head_dim)
        # -> (3, batch_size, num_heads, seq_len, head_dim)
        qkv = qkv.view(batch_size, seq_len, 3, self.num_heads, self.head_dim)
        qkv = qkv.permute(2, 0, 3, 1, 4)
        q, k, v = qkv[0], qkv[1], qkv[2]  # each: (batch_size, num_heads, seq_len, head_dim)

        # 3) Scaled dot-product attention
        # (batch_size, num_heads, seq_len, head_dim)
        #   @ (batch_size, num_heads, head_dim, seq_len)
        # -> (batch_size, num_heads, seq_len, seq_len)
        scores = torch.matmul(q, k.transpose(-2, -1))
        scores = scores / math.sqrt(self.head_dim)

        # 4) Mask (optional)
        if mask is not None:
            # The mask is applied to the attention score matrix, which has shape:
            # (batch_size, num_heads, seq_len, seq_len).
            # Each row corresponds to one query token; each column is a key token.
            # So a 0 at (i, j) means "query i cannot attend to key j".
            scores = scores.masked_fill(mask == 0, float("-inf"))

        # 5) Softmax to get attention weights
        attn_weights = F.softmax(scores, dim=-1)
        attn_weights = self.dropout(attn_weights)

        # 6) Weighted sum of values
        # (batch_size, num_heads, seq_len, seq_len)
        #   @ (batch_size, num_heads, seq_len, head_dim)
        # -> (batch_size, num_heads, seq_len, head_dim)
        context = torch.matmul(attn_weights, v)

        # 7) Merge heads back
        # (batch_size, num_heads, seq_len, head_dim)
        # -> (batch_size, seq_len, num_heads, head_dim)
        # -> (batch_size, seq_len, model_dim)
        context = context.transpose(1, 2).contiguous()
        context = context.view(batch_size, seq_len, self.model_dim)

        # 8) Final linear projection
        output = self.w_o(context)
        return output


if __name__ == "__main__":
    # Simple demo: batch of 2 sequences, length 4, model dim 8, 2 heads
    torch.manual_seed(0)
    x = torch.randn(2, 4, 8)
    mha = MultiHeadSelfAttention(model_dim=8, num_heads=2, dropout=0.1)
    y = mha(x)
    print("input shape:", x.shape)
    print("output shape:", y.shape)
