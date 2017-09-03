/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000
 */

// 是最长的连续的1s的个数，连续的0不算
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int con = 0, res = -1;
        if (*nums.begin() == 1)con = 1, res = 1;
        for (auto i = nums.begin() + 1; i != nums.end(); ++i) {
            if (*(i - 1) == *i && *i == 1)
                con++;
            else if (*i == 1)
                con = 1;
            else
                con = 0;
            if (con > res)
                res = con;
        }
        if (con > res)
            res = con;
        return res;
    }
};