/*
Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.

Please note that the string does not contain any non-printable characters.

Example:

Input: "Hello, my name is John"
Output: 5
 */

class Solution {
public:
    int countSegments(string s) {
        if (s == "")
            return 0;
        const char *ch = s.data();
        int cnt = 0;

        int state = 1;

        //状态0，读取到非空格时无操作；读取到空格时，进入状态1
        //状态1，读取到空格无操作；读取到非空格，cnt++并进入状态0
        int i = 0;
        while (*(ch + i) != '\0') {
            if (state == 0) {
                if (*(ch + i) == ' ')
                    state = 1;
            } else if (state == 1) {
                if (*(ch + i) != ' ') {
                    cnt++;
                    state = 0;
                }
            }
            ++i;
        }
        return cnt;
    }
};