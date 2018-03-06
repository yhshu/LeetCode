/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6.
 */

class Solution {
public:
    int maxProduct(vector<int> &nums) {
        const int size = nums.size();
        int product = nums[0]; // imax 是前i个数中最大乘积，imin 是前i个数中最小乘积
        for (int i = 1, imax = product, imin = product; i < size; i++) {
            if (nums[i] < 0)
                swap(imax, imin);
            imax = max(nums[i], imax * nums[i]);
            imin = min(nums[i], imin * nums[i]);
            product = max(product, imax);
        }
        return product;
    }
};