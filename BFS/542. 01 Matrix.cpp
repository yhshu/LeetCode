/*
Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.
Example 1:
Input:

0 0 0
0 1 0
0 0 0
Output:
0 0 0
0 1 0
0 0 0
Example 2:
Input:

0 0 0
0 1 0
1 1 1
Output:
0 0 0
0 1 0
1 2 1
 */

class Solution {
public:
    vector <vector<int>> updateMatrix(vector <vector<int>> &matrix) {
        const int m = matrix.size();
        const int n = matrix[0].size();
        vector <vector<int>> res(m, vector<int>(n, 0));
        bool visited[m * n + 10];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0)
                    res[i][j] = 0;
                else {
                    queue<int> que; // 每个点都是一次全新的BFS，需要重置visited和que
                    memset(visited, false, sizeof(visited));
                    que.push(i * n + j);
                    que.push(-1); // 层间分隔
                    int lev = 0;
                    while (!que.empty()) {
                        int cur = que.front();
                        que.pop();
                        if (cur == -1) {
                            lev++;
                            if (que.size() > 0)
                                que.push(-1);
                        } else {
                            if (visited[cur])
                                continue;
                            visited[cur] = true;
                            int x = cur / n;
                            int y = cur % n;
                            if (matrix[x][y] == 0) // 找到0
                                break;
                            else {
                                if (x - 1 >= 0) que.push(cur - n);
                                if (y + 1 < n) que.push(cur + 1);
                                if (x + 1 < m) que.push(cur + n);
                                if (y - 1 >= 0) que.push(cur - 1);
                            }
                        }
                    }
                    res[i][j] = lev;
                }
            }
        }
        return res;
    }
};