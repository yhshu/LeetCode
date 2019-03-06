/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

bool cmp(Interval a, Interval b) { return a.end < b.end; }

class Solution {
public:
  int eraseOverlapIntervals(vector<Interval> &intervals) {
    const int size = intervals.size();
    if (!size)
      return 0;
    sort(intervals.begin(), intervals.end(), cmp);
    int last = 0;
    int cnt = 1;
    for (int i = 1; i < size; i++) {
      if (intervals[i].start >= intervals[last].end) {
        last = i;
        cnt++;
      }
    }
    return size - cnt;
  }
};
