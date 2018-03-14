/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
 */

class Solution {
public:
    vector <string> restoreIpAddresses(string s) {
        vector <string> res;
        string IP;
        DFS(s, 0, 0, IP, res);
        return res;
    }

    void DFS(string &s, int start, int step, string IP, vector <string> &res) {
        // start是s的索引；step表示IP中的数字序号，范围[0,3]
        if (start == s.size() && step == 4) {
            IP.erase(IP.end() - 1); // 删掉第四个数之后的点
            res.push_back(IP);
            return;
        }
        // s.size() - start = 从start位起到最后一位的长度
        if (s.size() - start > (4 - step) * 3) // s太长，后面的每个数字最长3位仍有空余
            return;
        if (s.size() - start < (4 - step)) // 最后一个数的位数不够
            return;
        int num = 0;
        for (int i = start; i < start + 3; i++) { // 从start起遍历三位数字
            num = num * 10 + (s[i] - '0');
            if (num <= 255) { // 包括num==0的情况
                IP += s[i];
                DFS(s, i + 1, step + 1, IP + '.', res);
            }
            if (!num) // 0不能作为两位或三位数的开头
                break;
        }
    }
};