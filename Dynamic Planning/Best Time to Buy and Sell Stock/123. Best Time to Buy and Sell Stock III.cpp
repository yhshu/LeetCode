/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // 可进行最多两笔交易，买入前必须卖出当前持有的股票
        // dp[][0] 一次买入
        // dp[][1] 一次买入，一次卖出
        // dp[][2] 两次买入，一次卖出
        // dp[][3] 两次买入，两次卖出
        // dp的值是在股市的总盈亏

        int dp[2][4] = {INT_MIN, 0, INT_MIN, 0};
        const int size = prices.size();
        int cur = 0, next = 1;
        for (int i = 0; i < size; i++) {
            dp[next][0] = max(dp[cur][0], -prices[i]);
            dp[next][1] = max(dp[cur][1], dp[cur][0] + prices[i]);
            dp[next][2] = max(dp[cur][2], dp[cur][1] - prices[i]);
            dp[next][3] = max(dp[cur][3], dp[cur][2] + prices[i]);
            swap(cur, next);
        }
        return max(dp[cur][1], dp[cur][3]); // 可买卖一次或两次
    }
};