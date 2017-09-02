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
    char *start = s, *end = s + 1;
    int strlen = 0;//字符串总长度
    while (*start != '\0') {
        strlen++;
        start++;
    }
    int sublen = 1;//重复子串的长度
    while (*end != NULL) {
        if (*s != *end) {
            sublen++;
            end++;
        } else break;
    }

    if (strlen % sublen != 0)
        return false;
    end = s + sublen;
    start = s;
    while (end <= s + strlen) {
        if (*start == *end) {
            start++;
            end++;
        } else return false;
    }
    return true;
}