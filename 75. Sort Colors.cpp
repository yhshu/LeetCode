/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.
 */

class Solution {
public:
	void sortColors(vector<int>& nums) {
		int red = 0, white = 0, blue = 0;
		for (auto i = nums.begin(); i != nums.end(); ++i)
		{
			if (*i == 0)red++;
			else if (*i == 1)white++;
			else if (*i == 2)blue++;
		}
		while (nums.size())
			nums.pop_back();
		for (int j = 1; j <= red; j++)
			nums.push_back(0);
		for (int j = 1; j <= white; j++)
			nums.push_back(1);
		for (int j = 1; j <= blue; j++)
			nums.push_back(2);
	}
};