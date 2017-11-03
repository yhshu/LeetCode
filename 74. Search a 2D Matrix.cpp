/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
Given target = 3, return true.
*/

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		if (!n)
			return false;
		int m = matrix[0].size();
		if (!m)
			return false;
		int l = 0, r = m*n - 1;
		while (l != r)
		{
			int mid = (l + r) >> 1;
			if (matrix[mid / m][mid % m] < target)
				l = mid + 1;
			else
				r = mid;
		}
		return matrix[r / m][r % m] == target;
	}
};