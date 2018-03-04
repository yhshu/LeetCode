/*
Initially on a notepad only one character 'A' is present. You can perform two operations on this notepad for each step:

Copy All: You can copy all the characters present on the notepad (partial copy is not allowed).
Paste: You can paste the characters which are copied last time.
Given a number n. You have to get exactly n 'A' on the notepad by performing the minimum number of steps permitted. Output the minimum number of steps to get n 'A'.

Example 1:
Input: 3
Output: 3
Explanation:
Intitally, we have one character 'A'.
In step 1, we use Copy All operation.
In step 2, we use Paste operation to get 'AA'.
In step 3, we use Paste operation to get 'AAA'.
 */

// 两种操作
// 1.复制所有字符到剪贴板
// 2.粘帖

class Solution {
public:
    int minSteps(int n) {
        int dp[n + 1]; // dp[i]表示得到i个A需要的最小步骤数
        dp[1] = 0;
        for (int i = 2; i <= n; i++) {
            dp[i] = i; // dp[i]不应大于i
            for (int j = i - 1; j > 1; j--) {
                if (i % j == 0) {
                    dp[i] = dp[j] + (i / j); // 复制1次，粘帖(i/j-1)次
                    break;
                }
            }
        }
        return dp[n];
    }
};