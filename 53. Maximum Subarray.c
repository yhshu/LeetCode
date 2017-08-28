/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6.
 */
#define INT_MIN -2147483648

int maxSubArray(int *nums, int numsSize) {
    int j;
    int maxSum = *nums;//如果nums[]全为负数，应当返回*nums.
    int curSum = 0;
    for (j = 0; j != numsSize; ++j) {
        if (*(nums + j) + curSum >= *(nums + j))
            curSum += *(nums + j);
        else
            curSum = *(nums + j);
        if (curSum > maxSum)
            maxSum = curSum;
    }
    return maxSum;
}