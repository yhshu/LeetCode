/*
Given a list of sorted characters letters containing only lowercase letters, and given a target letter target, find the smallest element in the list that is larger than the given target.

Letters also wrap around. For example, if the target is target = 'z' and letters = ['a', 'b'], the answer is 'a'.

Examples:
Input:
letters = ["c", "f", "j"]
target = "a"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "c"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "d"
Output: "f"

Input:
letters = ["c", "f", "j"]
target = "g"
Output: "j"

Input:
letters = ["c", "f", "j"]
target = "j"
Output: "c"

Input:
letters = ["c", "f", "j"]
target = "k"
Output: "c"
 */

class Solution {
public:
    char nextGreatestLetter(vector<char> &letters, char target) {
        priority_queue<char, vector<char>, greater<char> > gr;
        priority_queue<char, vector<char>, greater<char> > sm;
        for (char c:letters) {
            if (c - target > 0)
                gr.push(c);
            else
                sm.push(c);
        }
        if (gr.size())
            return gr.top();
        else return sm.top();
    }
};