bool cmp(vector<int> &a, vector<int> &b) {
    return a[0] < b[0];
}

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() <= 1) return intervals;

        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> res;
        
        for (int i = 0; i < intervals.size(); i++) {
            vector<int> interval;
            if (res.empty()) {
                interval.push_back(intervals[i][0]);
                interval.push_back(intervals[i][1]);
            } else {
                if (res[res.size() - 1][1] >= intervals[i][0]) {
                    interval.push_back(res[res.size() - 1][0]);
                    interval.push_back(max(intervals[i][1], res[res.size() - 1][1]));
                    res.pop_back();
                } else {
                    interval.push_back(intervals[i][0]);
                    interval.push_back(intervals[i][1]);
                }
            }
            res.push_back(interval);
        }

        return res;
    }
};
