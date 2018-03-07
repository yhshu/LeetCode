/*
 * There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.

Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.

Example 1:
Input:
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle.
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input:
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends,
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.

 */


class Solution {
public:
    int F[205]; // 并查集使用

    int findCircleNum(vector <vector<int>> &M) {
        // 求无向图连通分支数量
        int res = 0;
        for (int i = 0; i < M.size(); i++) {
            F[i] = i;
        }
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (M[i][j] == 1) {
                    Union(i, j); // 使i加入j
                    break;
                }
            }
        }
        for (int i = 0; i < M.size(); i++) {
            if (Find(i) == i)
                res++;
        }
        return res;
    }

    int Find(int x) {
        if (x == F[x])
            return x;
        else return F[x] = Find(F[x]);
    }

    void Union(int x, int y) { // 使x加入y
        F[Find(x)] = Find(y);
    }
};