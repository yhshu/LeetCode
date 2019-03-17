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
            if (s.size() - i <= max_len / 2) // 以i为中点的回文子串最长不会超过已知最长回文子串的长度
                break;
            int l = i, r = i;
            while (r < s.size() - 1 && s[r] == s[r + 1]) // 重复字符是回文子串的一部分
                ++r;
            // 此时[l, r]中是相同的字符
            i = r + 1; // 下次搜索的起点
            while (l > 0 && r < s.size() - 1 && s[r + 1] == s[l - 1]) {
                // 扩张
                --l;
                ++r;
            }
            int this_len = r - l + 1;
            if (this_len > max_len) {
                min_start = l;
                max_len = this_len;
            }
        }
        return s.substr(min_start, max_len);
    }
};