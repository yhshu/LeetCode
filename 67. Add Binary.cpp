/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
 */
//https://fisherlei.blogspot.com/2013/01/leetcode-add-binary.html
class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string res;
        for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; --i, --j) {
            int ai = i >= 0 ? a[i] - '0' : 0;
            int bj = j >= 0 ? b[j] - '0' : 0;
            int val = (ai + bj + carry) % 2;
            carry = (ai + bj + carry) / 2;
            res.insert(res.begin(), val + '0');
        }
        if (carry == 1)//如果最高位要进位
            res.insert(res.begin(), '1');
        return res;
    }
};