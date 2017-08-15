/*
Implement atoi to convert a string to an integer.
Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
*/


// 考虑正负、空格、非数字的字符、溢出int范围
public class Solution {
    public int myAtoi(String str) {
        if (str == null || str.length() == 0)
            return 0;
        str = str.trim();//去除空格
        boolean sign = true;//正为true，负为false
        int i = 0;
        if (str.charAt(i) == '-') {
            sign = false;
            i++;
        } else if (str.charAt(i) == '+') {
            i++;
        }
        long ret = 0;
        for (; i != str.length(); i++) {
            int cur = str.charAt(i);
            if (cur < '0' || cur > '9')
                break;
            ret = ret * 10 + cur - '0';
            if (ret > Integer.MAX_VALUE) {
                if (sign)
                    return Integer.MAX_VALUE;
                else
                    return Integer.MIN_VALUE;
            }
        }
        return sign ? (int) ret : -1 * (int) ret;
    }
}