/*
Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.

This is case sensitive, for example "Aa" is not considered a palindrome here.

Note:
Assume the length of given string will not exceed 1,010.

Example:

Input:
"abccccdd"

Output:
7

Explanation:
One longest palindrome that can be built is "dccaccd", whose length is 7.
 */

class Solution {
public:
    int longestPalindrome(string s) {
        int res = 0;
        bool odd = false;
        unordered_map<char, int> map;
        for (char c:s)
            map[c]++;
        for (auto i = map.begin(); i != map.end(); ++i) {
            res += i->second;
            if (i->second % 2 == 1) {
                res -= 1;
                odd = true;
            }
        }
        if (odd)
            res++;
        return res;
    }
};