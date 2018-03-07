/*
Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:

S will be a string with length at most 12.
S will consist only of letters or digits.
 */

class Solution {
public:
    void backtrack(string &s, int i, vector <string> &res) {
        // 函数处理[i,size)区间内的排列
        if (i == s.size()) { // i的范围[0,size)
            res.push_back(s);
            return;
        }
        backtrack(s, i + 1, res);
        if (isalpha(s[i])) {
            s[i] ^= (1 << 5); // 大小写转换
            backtrack(s, i + 1, res);
        }
    }

    vector <string> letterCasePermutation(string S) {
        vector <string> res;
        backtrack(S, 0, res);
        return res;
    }
};