/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

int judgeRepeat(const char *start, const char *end) {
    //在字符串中返回移动长度，不在字符串中返回0，即不移动.
    int ret = 0;
    char *i = start;
    while (i != end) {
        if (*i == *end)
            return ret + 1;//跳转到重复字符后
        ret++;
        i++;
    }
    return 0;// 没有与*end 相同的字符，不移动，返回0
}

int lengthOfLongestSubstring(char *s) {
    if (*s == NULL)
        return 0;
    int ret = 1;//最终返回的最大子串长度
    int cnt = 1;//记录子串长度
    char *start = s, *end = s;

    for (; *end != NULL; ++end) {
        if (end - start < 0)start = end;
        else
            start += judgeRepeat(start, end);
        cnt = (end - start) + 1;
        if (cnt > ret)
            ret = cnt;
    }
    return ret;
}
