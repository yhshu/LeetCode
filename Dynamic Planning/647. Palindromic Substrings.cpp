/*
Given a string, your task is to count how many palindromic substrings in this string.

The substrings with different start indexes or end indexes are counted as different substrings even they consist of same characters.

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
 */

class Solution {
public:
    int count = 0;

    int countSubstrings(string s) { // string是C++基本数据类型，不要尝试!s或者s==nullptr
        if (s.size() == 0)
            return 0;
        for (int i = 0; i < s.size(); i++) {
            extendPalindrome(s, i, i); // 查找长度为奇数的回文串
            extendPalindrome(s, i, i + 1); // 查找长度为偶数的回文串
        }
        return count;
    }

    void extendPalindrome(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    }
};