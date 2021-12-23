/*
253. Meeting Rooms II

Given an array of meeting time intervals intervals where intervals[i] = [starti, endi], return the minimum number of conference rooms required.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: 2
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: 1
 

Constraints:

1 <= intervals.length <= 104
0 <= starti < endi <= 106

*/

bool cmp(const vector<int> &a, const vector<int> &b) {
    return a[0] < b[0]; // compare the start time
}

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return 0;

        sort(intervals.begin(), intervals.end(), cmp);
        priority_queue<int, vector<int>, greater<int>> que;
        for(auto &interval: intervals) {
            if (!que.empty() && que.top() <= interval[0]) {
                que.pop();
            }
            que.push(interval[1]);
        }
        return que.size();
    }
};
