/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
 */

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0); // dp[i] = i个数能组成的BST个数
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
                // 一个有i个结点的BST：左子树j-1个结点，右子树i-j个结点
            }
        }
        return dp[n];
    }
};