/*
Write a function to find the longest common prefix string amongst an array of strings.
 */

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string prefix;
		if (!strs.size())
			return prefix;
		for (int pos = 0; pos != strs[0].size(); pos++)//遍历每一位;最长前缀的长度不超过strs[0]的长度
		{
			for (int i = 1; i < strs.size(); i++)//遍历向量strs中每个str
			{
				if (strs[i].size() == pos || strs[i][pos] != strs[0][pos])
					return prefix;
			}
			prefix.push_back(strs[0][pos]);
		}
		return prefix;
	}
};