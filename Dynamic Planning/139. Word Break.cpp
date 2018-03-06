/*
Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.

For example, given
s = "leetcode",
dict = ["leet", "code"].

Return true because "leetcode" can be segmented as "leet code".

UPDATE (2017/1/4):
The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.
 */

class Solution {
public:
    bool wordBreak(string s, vector <string> &wordDict) {
        if (wordDict.size() == 0) // 词典为空
            return false;
        vector<int> dp(s.size() + 1, 0);
        // dp[i]为1表示前i个字符组成的串可分，为0表示前i个字符组成的串不可分
        dp[0] = 1;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j]) {
                    string word = s.substr(j, i - j); // word == s[j, i-j)
                    if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                        dp[i] = 1;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};