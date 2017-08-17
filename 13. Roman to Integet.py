# coding=utf-8
# Given a roman numeral, convert it to an integer.
# Input is guaranteed to be within the range from 1 to 3999.

# 如果当前数字是最后一个数字，或之后的数字比它小，则加上当前数字。
# 否则，减去当前数字。

class Solution(object):
	def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
		res = 0
		dict = {'I': 1, 'V': 5, 'X': 10, 'L': 50, 'C': 100, 'D': 500, 'M': 1000}
        for i in range(0, len(s)): # i的范围是 0 到 len(s)-1 
            if i == len(s) - 1 or dict[s[i+1]] <= dict[s[i]]:
                res += dict[s[i]]
            else:
                res -= dict[s[i]]
        return res
