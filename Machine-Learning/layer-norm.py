import torch
import torch.nn as nn

class LayerNorm(nn.Module):
    def __init__(self, num_features, eps=1e-5):
        super().__init__()
        self.eps = eps
        self.gamma = nn.Parameter(torch.ones(num_features))
        self.beta = nn.Parameter(torch.zeros(num_features))

    def forward(self, x):
        # x shape: (Batch, Seq_Len, Dim) 
        # LN normalizes over the last dimension (Dim)
        
        # 1. Compute mean and variance (keepdim=True keeps shapes aligned)
        mean = x.mean(dim=-1, keepdim=True)
        var = x.var(dim=-1, keepdim=True, unbiased=False)
        
        # 2. Normalize
        x_hat = (x - mean) / torch.sqrt(var + self.eps)
        
        # 3. Scale and shift
        return self.gamma * x_hat + self.beta

def main():
    torch.manual_seed(0)
    batch_size = 2
    seq_len = 3
    dim = 4

    x = torch.randn(batch_size, seq_len, dim)
    print("Input shape:", tuple(x.shape))
    print("Input sample:\n", x)

    ln = LayerNorm(dim)
    y = ln(x)
    print("\nOutput shape:", tuple(y.shape))
    print("Output sample:\n", y)

if __name__ == "__main__":
    main()
