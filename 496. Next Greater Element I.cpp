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

class Solution {
public:
    vector<int> nextGreaterElement(vector<int> &findNums, vector<int> &nums) {
        vector<int> res(findNums.size());
        unordered_map<int, int> map;
        for (int i = 0; i != nums.size(); ++i) {
            map[nums[i]] = i;// 用map记录nums每个元素的索引
        }
        for (int i = 0; i != findNums.size(); ++i) {
            res[i] = -1;
            int start = map[findNums[i]];
            for (int j = start + 1; j != nums.size(); ++j) {
                if (nums[j] > findNums[i]) {
                    res[i] = nums[j];
                    break;
                }
            }
        }
        return res;
    }
};