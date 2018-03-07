/*
A string S of lowercase letters is given. We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.

Example 1:
Input: S = "ababcbacadefegdehijhklij"
Output: [9,7,8]
Explanation:
The partition is "ababcbaca", "defegde", "hijhklij".
This is a partition so that each letter appears in at most one part.
A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
Note:

S will have length in range [1, 500].
S will consist of lowercase letters ('a' to 'z') only.
 */

class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> res;
        const int size = S.size();
        if (!size)
            return res;
        int map[26] = {0}; // 记录每个字母最后出现的位置
        for (int i = 0; i < size; i++) {
            map[S[i] - 'a'] = i;
        }
        int last = 0;
        int start = 0;
        for (int i = 0; i < size; i++) {
            last = max(last, map[S[i] - 'a']); // map[S[i] - 'a'] 大于等于i
            if (last == i) { // 如果当前字母是最后一次出现，则可以分段
                res.push_back(last - start + 1);
                start = last + 1;
            }
        }
        return res;
    }
};