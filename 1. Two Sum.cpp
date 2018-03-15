class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map; // 记录数字的索引
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            int toFind = target - nums[i];
            if (map.find(toFind) != map.end()) { // 在map找到toFind的索引
                res.push_back(map[toFind]);
                res.push_back(i);
                return res;
            } // else 没有找到，将nums[i]插入map，如果后续遇到target-nums[i]就可在map中找到
            map[nums[i]] = i;
        }
        return res;
    }
};