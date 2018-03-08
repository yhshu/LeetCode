/*
You're given strings J representing the types of stones that are jewels, and S representing the stones you have.  Each character in S is a type of stone you have.  You want to know how many of the stones you have are also jewels.

The letters in J are guaranteed distinct, and all characters in J and S are letters. Letters are case sensitive, so "a" is considered a different type of stone from "A".

Example 1:

Input: J = "aA", S = "aAAbbbb"
Output: 3
Example 2:

Input: J = "z", S = "ZZ"
Output: 0
 */

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int res = 0;
        set<char> setJ(J.begin(), J.end()); // J元素集合
        for (char c:S)
            if (setJ.count(c)) // 逐个判断S中的字符是否存在于J中
                res++;
        return res;
    }
};