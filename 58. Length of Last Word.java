/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example,
Given s = "Hello World",
return 5.
 */
class Solution {
    public int lengthOfLastWord(String s) {
        if (s.equals(""))
            return 0;
        int cnt = 0;
        boolean word = false;
        char[] ch = s.toCharArray();
        for (int i = ch.length - 1; i != -1; --i) {
            if (ch[i] != ' ') word = true;
            if (word) {
                if (ch[i] == ' ') break;
                cnt++;
            }
        }
        return cnt;
    }
}