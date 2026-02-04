import torch
import torch.nn as nn
import torch.nn.functional as F
import math

class SelfAttention(nn.Module):
    def __init__(self, model_dim):
        super().__init__()
        self.model_dim = model_dim
        # Define three linear projection matrices
        self.w_q = nn.Linear(model_dim, model_dim)
        self.w_k = nn.Linear(model_dim, model_dim)
        self.w_v = nn.Linear(model_dim, model_dim)

    def forward(self, x, mask=None):
        # x shape: (Batch_Size, Seq_Len, model_dim)
        
        # 1. Generate Q, K, V
        Q = self.w_q(x) 
        K = self.w_k(x)
        V = self.w_v(x)
        
        # 2. Compute attention scores: Q @ K.T
        # Note: transpose the last two dimensions of K for dot product
        # (Batch, Seq, Dim) @ (Batch, Dim, Seq) -> (Batch, Seq, Seq)
        scores = torch.matmul(Q, K.transpose(-2, -1))
        
        # 3. Scale
        scores = scores / math.sqrt(self.model_dim)
        
        # 4. Mask (optional, e.g., in a decoder)
        if mask is not None:
            # Fill positions where mask == 0 with -inf
            scores = scores.masked_fill(mask == 0, float('-inf'))
        
        # 5. Softmax (normalize to probabilities per dimension)
        attn_weights = F.softmax(scores, dim=-1)
        
        # 6. Weighted sum: Weights @ V
        # (Batch, Seq, Seq) @ (Batch, Seq, Dim) -> (Batch, Seq, Dim)
        output = torch.matmul(attn_weights, V)
        
        return output


def main():
    torch.manual_seed(0)
    batch_size = 2
    seq_len = 4
    model_dim = 8

    x = torch.randn(batch_size, seq_len, model_dim)
    attn = SelfAttention(model_dim)
    output = attn(x)

    print("Input shape:", x.shape)
    print("Output shape:", output.shape)
    print("Output (first batch, first token):", output[0, 0])


if __name__ == "__main__":
    main()
