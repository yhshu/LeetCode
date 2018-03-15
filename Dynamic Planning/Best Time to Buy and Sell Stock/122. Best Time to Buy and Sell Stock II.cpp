/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


 */

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // 可进行多次交易，但买入之前必须卖出当前持有的股票
        if (prices.size() <= 1)return 0;
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            res += max(0, prices[i] - prices[i - 1]);
        }
        return res;
    }
};