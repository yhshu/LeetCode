/*
Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.

Example 1:
Input:

"bbbab"
Output:
4
One possible longest palindromic subsequence is "bbbb".
Example 2:
Input:

"cbbd"
Output:
2
One possible longest palindromic subsequence is "bb".
 */

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        int dp[size + 10][size + 10] = {0};
        for (int left = size - 1; left >= 0; left--) {
            dp[left][left] = 1;
            for (int right = left + 1; right < size; right++) {
                if (s[left] == s[right]) {
                    dp[left][right] = 2 + dp[left + 1][right - 1];
                } else {
                    dp[left][right] = max(dp[left + 1][right], dp[left][right - 1]);
                }
            }
        }
        return dp[0][size - 1];
    }
};