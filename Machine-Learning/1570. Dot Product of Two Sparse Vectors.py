# Given two Sparse vectors, compute their dot product.
# Implement class SparseVector:
# __init__: initialize the sparse vector with the given list
# method dotProduct: compute the dot product between two Sparse Vectors
# Sparse vector means most of its elements are zero. You should store the sparse vector in an efficient way.

class SparseVector:
    def __init__(self, nums):
        # Store only non-zero elements with their indices
        self.data = {idx: num for idx, num in enumerate(nums) if num != 0} 

    def dotProduct(self, vec):
        # Compute the dot product using only non-zero elements
        result = 0
        for idx, val in self.data.items():
            if idx in vec.data:
                result += val * vec.data[idx]
        return result