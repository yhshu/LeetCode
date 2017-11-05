/*
Given the coordinates of four points in 2D space, return whether the four points could construct a square.

The coordinate (x,y) of a point is represented by an integer array with two integers.

Example:
Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
Output: True
Note:

All the input integers are in the range [-10000, 10000].
A valid square has four equal sides with positive length and four equal angles (90-degree angles).
Input points have no order.
*/

//矩形任一边长均不为0！
class Solution {
public:
	int EuclidDistance(vector<int> a, vector<int>b)
	{
		return (a[0] - b[0])*(a[0] - b[0]) + (a[1] - b[1])*(a[1] - b[1]);
	}
	bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
		unordered_set<int>set({ EuclidDistance(p1,p2),EuclidDistance(p1,p3),EuclidDistance(p1,p4),EuclidDistance(p2,p3),EuclidDistance(p2,p4),EuclidDistance(p3,p4) });
		return !set.count(0) && set.size() == 2;
	}
};