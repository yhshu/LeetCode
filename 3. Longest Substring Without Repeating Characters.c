/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

int inString(const char *start, const char *end, const char ch) {
    //在字符串中返回1，不在字符串中返回0.
    char *i = start;
    while (i != end) {
        if (*i != ch)
            i++;
        else return 1;
    }
    if (*end == ch)
        return 1;
    return 0;
}

int lengthOfLongestSubstring(char *s) {
    if (*s == NULL)
        return 0;
    int ret = 1;//最终返回的最大子串长度
    int cnt = 1;//记录子串长度
    char *start = s, *end = s;

    int i;
    for (i = 1; *(s + i) != NULL; ++i) {
        if (inString(start, end, *(s + i))) {
            if (start == end) {
                start++;
                end++;
            } else {
                start++;
                cnt = (end - start) + 1;
            }
        } else {
            end++;
            cnt++;
        }
        if (cnt > ret)
            ret = cnt;
    }
    return ret;
}
