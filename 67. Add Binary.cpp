/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
 */

class Solution {
public:
    string XOR(string a, string b, int len) {
        string res = "";
        for (int i = len - 1; i != -1; --i) {
            if ((a[i] == '1' && b[i] == '0') || (a[i] == '0' && b[i] == '1'))
                res[i] = '1';
            else res[i] = '0';
        }
        return res;
    }

    string AND(string a, string b, int len) {
        string res = "";
        for (int i = len - 1; i != -1; --i) {
            if (a[i] == '1' && b[i] == '1')
                res[i] = '1';
            else res[i] = '0';
        }
        return res;
    }

    bool isZeros(string str) {
        for (int i = 0; i != str.length(); ++i)
            if (str[i] != '0')return false;
        return true;
    }

    string LeftShiftOne(string str, int len) {
        string res = "";
        for (int i = 0; i != len - 1; ++i) {
            res[i] = str[i + 1];
        }
        res[len] = '0';
        return res;
    }

    string ADD(string a, string b, int len) {
        string carry = AND(a, b, len);
        if (isZeros(carry))
            return XOR(a, b, len);
        else return ADD(XOR(a, b, len), LeftShiftOne(AND(a, b, len), len), len);
    }

    string addBinary(string a, string b) {
        int len = max(a.length(), b.length());
        //将两数位对齐
        while (a.length() < len)
            a = "0" + a;
        while (b.length() < len)
            b = "0" + b;
        return ADD(a, b, len);
    }
};