/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.

Example:

Input: "babad"

Output: "bab"

Note: "aba" is also a valid answer.


Example:

Input: "cbbd"

Output: "bb"
 */

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";
        else if (s.size() == 1)
            return s;
        int min_start = 0, max_len = 1;
        for (int i = 0; i < s.size();) {
            if (s.size() - i <= max_len / 2)
                break;
            int left = i, right = i;
            while (k < s.size() - 1 && s[right] == s[right + 1]) // 跳过重复字符
                ++right;
            i = right + 1; // 下次搜索的起点
            while (left > 0 && right < s.size() - 1 && s[right + 1] == s[left - 1]) {
                // 扩张
                --left;
                ++right;
            }
            int this_len = right - left + 1;
            if (this_len > max_len) {
                min_start = left;
                max_len = this_len;
            }
        }
        return s.substr(min_start, max_len);
    }
};