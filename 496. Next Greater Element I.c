/*
You are given two arrays (without duplicates) nums1 and nums2 where nums1’s elements are subset of nums2. Find all the next greater numbers for nums1's elements in the corresponding places of nums2.

The Next Greater Number of a number x in nums1 is the first greater number to its right in nums2. If it does not exist, output -1 for this number.

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2].
Output: [-1,3,-1]
Explanation:
    For number 4 in the first array, you cannot find the next greater number for it in the second array, so output -1.
    For number 1 in the first array, the next greater number for it in the second array is 3.
    For number 2 in the first array, there is no next greater number for it in the second array, so output -1.
Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4].
Output: [3,-1]
Explanation:
    For number 2 in the first array, the next greater number for it in the second array is 3.
    For number 4 in the first array, there is no next greater number for it in the second array, so output -1.
Note:
All elements in nums1 and nums2 are unique.
The length of both nums1 and nums2 would not exceed 1000.
 */

/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *nextGreaterElement(int *findNums, int findNumsSize, int *nums, int numsSize, int *returnSize) {
    // findNumsSize 是nums1 大小，numsSize是nums2 大小
    *returnSize = findNumsSize;
    int *ret = (int *) malloc(findNumsSize * sizeof(int));
    for (int i = 0; i != findNumsSize; ++i)//遍历findNums
        for (int j = 0; j != numsSize; ++j)//遍历nums
        {
            if (*(findNums + i) == *(nums + j))//findNums中的元素在nums中找到
            {
                int k = j + 1;
                for (; k != numsSize; ++k) // 找下一个更大的元素
                {
                    if (*(nums + k) > *(nums + j)) {
                        *(ret + i) = *(nums + k);
                        break;
                    }

                }
                if (k == numsSize) {//未找到更大的元素
                    *(ret + i) = -1;
                }
                break;
            }
        }
    return ret;
}