class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        if (a == 0 && b == 0 && c == 0) return "";
        
        string res = "";
        int maxLen = a + b + c;
        vector<pair<int, char>> nums{{a, 'a'}, {b, 'b'}, {c, 'c'}};
        while (res.size() <= maxLen) {
            char ban = 'x';
            int len = res.size();
            if (len >= 2 && res[len - 1] == res[len - 2]) {
                ban = res[len - 1];
            }
            // Find the most frequent number in nums right now
            int idx = -1;
            char cur = 'x';
            for (int i = 0; i < 3; i++) {
                if (nums[i].second == ban || nums[i].first == 0) 
                    continue;
                if (idx == -1) {
                    idx = i;
                    cur = nums[i].second;
                } else if (nums[i].first > nums[idx].first) {
                    idx = i;
                    cur = nums[i].second;
                }
            }

            if (idx != -1) {
                nums[idx].first -= 1;
                res += nums[idx].second;
            } else break;
        }
        return res;
    }
};
