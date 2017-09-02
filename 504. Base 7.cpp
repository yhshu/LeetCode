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

//反转字符串
char *strrev(char *str) {
    char *p1, *p2;

    if (!str || !*str)
        return str;
    for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2) {
        *p1 ^= *p2;
        *p2 ^= *p1;
        *p1 ^= *p2;
    }
    return str;
}

//10进制整数转换为7进制（字符串）
class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
            return "0";
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
        res[i + 1] = '\0';
        strrev(res);
        return res;
    }
};

