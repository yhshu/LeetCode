/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
 */

class Solution {
public:
    vector <string> generateParenthesis(int n) {
        vector <string> res;
        string str = "";
        backtrack(res, str, 0, 0, n);
        return res;
    }

    void backtrack(vector <string> &res, string str, int left, int right, int &n) {
        // res 需返回的字符串向量
        // str 当前回溯的字符串
        // left 当前左括号个数
        // right 当前右括号个数
        // n 括号对数
        if (str.size() == 2 * n) { // 当前字符串满足条件，添加到res
            res.push_back(str);
            return;
        }
        if (left < n)
            backtrack(res, str + "(", left + 1, right, n);
        if (right < left)
            backtrack(res, str + ")", left, right + 1, n);
    }
};
