/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
 */

class Solution {
public:
    void DFS(vector <string> &res, string sol, string &digits, int step, vector <string> &keyBoard) {
        if (step == digits.size()) {
            res.push_back(sol);
            return;
        }
        int key = digits[step] - '0' - 2; // char减'0'转int
        for (int i = 0; i < keyBoard[key].size(); i++) {
            sol.push_back(keyBoard[key][i]);
            DFS(res, sol, digits, step + 1, keyBoard);
            sol.pop_back();
        }
    }

    vector <string> letterCombinations(string digits) {
        vector <string> res;
        if (digits.size() == 0)
            return res;
        string sol;
        vector <string> keyBoard = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        DFS(res, sol, digits, 0, keyBoard);
        return res;
    }
};