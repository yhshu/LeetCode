/*
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

Note:
Each element in the result must be unique.
The result can be in any order.
 */
class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        map<int, bool> exist;
        vector<int> res;
        if (nums1.empty() || nums2.empty())
            return res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (auto i = nums1.begin(), j = nums2.begin(); i != nums1.end() && j != nums2.end();) {
            if (*i < *j)
                ++i;
            else if (*i > *j)
                ++j;
            else {
                if (!exist[*i])
                    res.push_back(*i);
                exist[*i] = true;
                ++i;
                ++j;
            }
        }
        return res;
    }
};