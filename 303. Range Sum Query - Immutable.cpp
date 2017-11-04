/*
Given an integer array nums, find the sum of the elements between indices i and j (i ¡Ü j), inclusive.

Example:
Given nums = [-2, 0, 3, -5, 2, -1]

sumRange(0, 2) -> 1
sumRange(2, 5) -> -1
sumRange(0, 5) -> -3
*/

class NumArray {
public:
	NumArray(vector<int> nums) {
		sum.push_back(0);
		for (auto num : nums)
		{
			sum.push_back(sum.back() + num);
		}
	}

	int sumRange(int i, int j) {
		return sum[j + 1] - sum[i];
	}
private:
	vector<int>sum;
};


/**
* Your NumArray object will be instantiated and called as such:
* NumArray obj = new NumArray(nums);
* int param_1 = obj.sumRange(i,j);
*/