/*
Given an integer, return its base 7 string representation.

Example 1:
Input: 100
Output: "202"
Example 2:
Input: -7
Output: "-10"
Note: The input will be in range of [-1e7, 1e7].

 */

//10进制整数转换为7进制（字符串）
class Solution {
public:
    string convertToBase7(int num) {
        char res[10] = {0};
        int i = 0;
        bool sign;
        if (num >= 0)
            sign = true;
        else
            sign = false;
        num = (num < 0) ? -num : num;
        while (num != 0) {
            res[i++] = (num % 7) + '0';
            num /= 7;
        }
        if (!sign)
            res[i] = '-';
        //反转字符串
        return res;
    }
};