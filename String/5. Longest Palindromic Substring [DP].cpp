class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        const int size = s.size();
        if(!size) return res;
        int dp[size][size]; // dp[i][j] is the size of the longest palindromic substring of s.substr(i, j + 1)
        memset(dp, 0, sizeof(dp));
        
        int begin = 0, len = 1;
        for(int i = 0; i < size; i++){
            dp[i][i] = 1;
            if(i < size - 1) {
                if(s[i] == s[i + 1]){
                    dp[i][i + 1] = 2;
                    begin = i;
                    len = 2;
                }
            }
        }

        for(int l = 3; l <= size; l++){
            for(int i = 0; i + l - 1 < size; i++){
                int j = i + l - 1;
                if(s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                    begin = i;
                    len = l;
                }
            }
        }
        return s.substr(begin, len);
    }
};
