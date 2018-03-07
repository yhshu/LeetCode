/*
Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq; // 小根堆
        for (auto &n:nums) {
            if (pq.size() < k) {
                pq.emplace(n);
            } else if (n > pq.top()) // 使得小根堆pq的大小保持在k
            {
                pq.pop();
                pq.emplace(n);
            }
        }
        return pq.top();
    }
};