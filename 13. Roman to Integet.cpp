/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

/*
如果当前数字是最后一个数字，或之后的数字比它小，则加上当前数字。
否则，减去当前数字。
*/
class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
		unordered_map<char, int> m {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
		for (int i = 0; i != s.size(); ++i)
		{
			if(i == s.size() -1 || m[s[i+1]] <= m[s[i]])
				res += m[s[i]];
			else
				res -= m[s[i]];
		}
		return res;
    }
};