/*
Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number, and n does not exceed 1690.
 */


// 丑陋数的定义是，质因子只含有2、3、5的正数。
// 1被当做丑陋数，n不超过1690.

// 每个丑陋数都等于一个更小的丑陋数乘以2, 3或5中的一个数
// 丑陋数序列是 1 2 3 4 5 6 8 9 10 12 …
// 可写为如下形式
// 1) 1x2 2x2 3x2 4x2 5x2 6x2 8x2 9x2 10x2 12x2 15x2
// 2) 1x3 2x3 3x3 4x3 5x3 6x3 8x3 9x3 10x3 12x3 15x3
// 3) 1x5 2x5 3x5 4x5 5x5 6x5 8x5 9x5 10x5 12x5 15x5

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0)return 0;
        if (n == 1)return 1;
        int f2 = 0, f3 = 0, f5 = 0; // 如上所示的三行的三个指针
        vector<int> dp(n); // dp[i-1]表示第i个丑陋数
        dp[0] = 1; // 1是首个丑陋数
        for (int i = 1; i < n; i++) {
            dp[i] = min(dp[f2] * 2, min(dp[f3] * 3, dp[f5] * 5));
			// 下面三个if不一定只满足一个
            if (dp[i] == dp[f2] * 2)f2++;
            if (dp[i] == dp[f3] * 3)f3++;
            if (dp[i] == dp[f5] * 5)f5++;
        }
        return dp[n - 1];
    }
};