/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array nums = [1,1,2],

Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.

 */
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty())return 0;
        if (nums.begin() == nums.end() - 1)return 1;
        int cnt = 1;
        for (auto i = nums.begin() + 1; i != nums.end(); ++i) {
            if (*(i - 1) != *i)
                cnt++;
        }
        return cnt;
    }
};