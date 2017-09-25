/*
Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/

class Solution {
public:
	bool detectCapitalUse(string word) {
		//三种情况：全小写、首字母大写、全大写
		const char *ch = word.data();
		bool LowerExist;
		bool AllCap;
		int i = 0;
		if (*ch - 'a' >= 0 && *ch - 'z' <= 0)
		{
			while (*(ch + i))
			{
				if (*(ch + i) - 'a' < 0 || *(ch + i) - 'z' > 0)
					return false;
				++i;
			}
			return true;
		}
		else if (*ch - 'A' >= 0 && *ch - 'Z' <= 0)
		{
			LowerExist = false;
			AllCap = false;
			if (*(ch + 1) - 'A' >= 0 && *(ch + 1) - 'Z' <= 0)//大写
				AllCap = true;
			while (*(ch + i))
			{
				if (*(ch + i) - 'a' >= 0 && *(ch + i) - 'z' <= 0)//小写
				{
					if (AllCap)
						return false;
					AllCap = false;
					LowerExist = true;
				}
				else if (LowerExist && (*(ch + i) - 'A' >= 0) && (*(ch + i) - 'Z' <= 0))//前面存在小写又读到大写
					return false;
				++i;
			}
			return true;
		}
	}
};
