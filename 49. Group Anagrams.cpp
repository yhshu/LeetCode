class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> m;
        if (strs.size() <= 1) {
            res.push_back(strs);
            return res;
        }
        
        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (m.find(s) == m.end()) {
                m[s] = vector<string>();
            }
            m[s].push_back(strs[i]);
        }

        for (auto it = m.begin(); it != m.end(); it++) {
            res.push_back(it->second);
        }
        return res;
    }
};
