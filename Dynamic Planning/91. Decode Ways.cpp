/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
 */

class Solution {
public:
    int numDecodings(string s) {
        const int size = s.size();
        if (size == 0)return 0;
        int dp[size + 1] = {0}; // dp[i]表示前i个字符的解码方法数
        dp[0] = 1;
        dp[1] = (s[0] != '0') ? 1 : 0;
        for (int i = 2; i <= size; i++) {
            if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) { // 最后两位构成10~26
                dp[i] = dp[i - 2];
                if (s[i - 1] != '0')
                    dp[i] += dp[i - 1];
            } else if (s[i - 1] != '0')
                dp[i] = dp[i - 1];
        }
        return dp[size];
    }
};