import torch
import torch.nn as nn

class BatchNorm1d(nn.Module):
    def __init__(self, num_features, eps=1e-5, momentum=0.1):
        super().__init__()
        self.eps = eps
        self.momentum = momentum
        # Learnable parameters
        self.gamma = nn.Parameter(torch.ones(num_features))
        self.beta = nn.Parameter(torch.zeros(num_features))
        # Running statistics (buffers, not Parameters; no gradients)
        self.register_buffer('running_mean', torch.zeros(num_features))
        self.register_buffer('running_var', torch.ones(num_features))

    def forward(self, x):
        # x shape: (Batch, Num_Features)
        if self.training:
            # 1. Compute batch mean and variance
            batch_mean = x.mean(dim=0)
            batch_var = x.var(dim=0, unbiased=False)
            
            # 2. Normalize
            x_hat = (x - batch_mean) / torch.sqrt(batch_var + self.eps)
            
            # 3. Update running statistics (exponential moving average)
            # running_mean = (1 - m) * old + m * new
            self.running_mean = (1 - self.momentum) * self.running_mean + self.momentum * batch_mean
            self.running_var = (1 - self.momentum) * self.running_var + self.momentum * batch_var
        else:
            # Inference: use running statistics
            x_hat = (x - self.running_mean) / torch.sqrt(self.running_var + self.eps)
            
        # 4. Scale and shift
        return self.gamma * x_hat + self.beta

def main():
    torch.manual_seed(0)
    batch_size = 4
    num_features = 3

    x = torch.randn(batch_size, num_features)
    print("Input shape:", tuple(x.shape))
    print("Input sample:\n", x)

    bn = BatchNorm1d(num_features)
    bn.train()
    y_train = bn(x)
    print("\nTrain mode output shape:", tuple(y_train.shape))
    print("Train mode output sample:\n", y_train)

    bn.eval()
    y_eval = bn(x)
    print("\nEval mode output shape:", tuple(y_eval.shape))
    print("Eval mode output sample:\n", y_eval)

if __name__ == "__main__":
    main()
