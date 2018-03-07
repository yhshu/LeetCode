/*
Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some email that is common to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

Example 1:
Input:
accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
Explanation:
The first and third John's are the same person as they have the common email "johnsmith@mail.com".
The second John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'],
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Note:

The length of accounts will be in the range [1, 1000].
The length of accounts[i] will be in the range [1, 10].
The length of accounts[i][j] will be in the range [1, 30].
 */

class Solution {
public:
    vector <vector<string>> accountsMerge(vector <vector<string>> &accounts) {
        vector <vector<string>> res;
        map <string, string> parent; // 邮箱到用户id的映射，用于并查集
        map <string, string> owner; // 邮箱到用户姓名的映射
        map <string, set<string>> unions; // 主邮箱到该用户所有邮箱的集合的映射
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                parent[accounts[i][j]] = accounts[i][j];
                owner[accounts[i][j]] = accounts[i][0];
            }
        }
        for (int i = 0; i < accounts.size(); i++) {
            string connect = find(accounts[i][1], parent);
            for (int j = 2; j < accounts[i].size(); j++) {
                parent[find(accounts[i][j], parent)] = connect;
            }
        }
        for (int i = 0; i < accounts.size(); i++) {
            for (int j = 1; j < accounts[i].size(); j++)
                // 每个邮箱都与对应的主邮箱关联
                unions[find(accounts[i][j], parent)].insert(accounts[i][j]);
        }
        for (pair <string, set<string>> p:unions) {
            // 获取该用户的所有邮箱
            vector <string> emails(p.second.begin(), p.second.end());
            // 添加用户名到首位
            emails.insert(emails.begin(), owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }

    string find(string s, map <string, string> &par) {
        if (par[s] == s)
            return s;
        return find(par[s], par);
    }
};