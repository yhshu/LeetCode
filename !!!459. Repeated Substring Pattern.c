/*
Given a non-empty string check if it can be constructed by taking a substring of it and appending multiple copies of the substring together. You may assume the given string consists of lowercase English letters only and its length will not exceed 10000.

Example 1:
Input: "abab"

Output: True

Explanation: It's the substring "ab" twice.
Example 2:
Input: "aba"

Output: False
Example 3:
Input: "abcabcabcabc"

Output: True

Explanation: It's the substring "abc" four times. (And the substring "abcabc" twice.)

 */

bool repeatedSubstringPattern(char *s) {
    int len = 0;
    int *p = s;
    bool flag = true, flag1 = true;
    while (*p != '\0') {
        len++;
        p++;
    }
    int i, j, k;
    for (i = 1; i <= len / 2; ++i) //i 是子串长度
    {
        flag1 = true;
        if (len % i != 0)
            continue;
        for (j = 0; j != i; ++j)//遍历子串中的每个字符
        {
            flag = true;
            k = 1;
            while (j + k * i < len) {
                if (*(s + j + k * i) != *(s + j)) {
                    flag = false;
                    break;
                }
                k++;
            }
            if (!flag) {
                flag1 = false;
                break;
            }
        }
        if (flag1)
            return true;
    }
    return false;
}
