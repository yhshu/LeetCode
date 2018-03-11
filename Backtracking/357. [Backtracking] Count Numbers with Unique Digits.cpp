/*
Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

Example:
Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
 */

class Solution {
public:
    int cnt = 0;
    bool vis[12];

    void DFS(int step, int &n, bool zero) {
        if (step == n) {
            cnt++;
            return;
        } else {
            for (int i = 0; i <= 9; i++) {
                if (i != 0)zero = false;
                if (!vis[i] || zero) {
                    vis[i] = true;
                    DFS(step + 1, n, zero);
                    vis[i] = false;
                }
            }
        }
    }

    int countNumbersWithUniqueDigits(int n) {
        // 所有数字不能重复，隐含的前导0除外
        // 使用zero标记当前是否是前导0
        DFS(0, n, true);
        return cnt;
    }
};
