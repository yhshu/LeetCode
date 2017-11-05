/*
 * Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
	 [2],
	[3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
 */

class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int len = triangle.size();
		if (!len)
			return 0;
		int res = triangle[0][0];
		int j = 0;
		for (auto i = 1; i != len; i++)
		{
			if (triangle[i][j] <= triangle[i][j + 1])
				res += triangle[i][j];
			else
				res += triangle[i][++j];
		}
		return res;
	}
};