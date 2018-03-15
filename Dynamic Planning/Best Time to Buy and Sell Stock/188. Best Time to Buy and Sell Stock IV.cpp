/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        // 可进行最多k笔交易，买入前必须卖出当前持有的股票
        const int size = prices.size();
        if (size <= 1)return 0;
        if (k >= size / 2) { // 允许每天都买入与卖出
            int maxPro = 0; // 最大利润
            for (int i = 1; i < size; i++) {
                if (prices[i] > prices[i - 1]) { // 只要今天比昨日股价高，就昨天买今天卖
                    maxPro += prices[i] - prices[i - 1];
                }
            }
            return maxPro;
        }
        int dp[k + 1][size] = {}; // dp[i][j] 表示在i笔交易以内从prices[0...j]中可获得的最大利润
        for (int i = 1; i <= k; i++) {
            int localMax = -prices[0];
            for (int j = 1; j < size; j++) {
                dp[i][j] = max(dp[i][j - 1], prices[j] + localMax); // 考虑卖出
                localMax = max(localMax, dp[i - 1][j - 1] - prices[j]); // 考虑买入
            }
        }
        return dp[k][size - 1];
    }
};