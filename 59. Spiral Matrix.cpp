/*
 * Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
 */

class Solution {
public:
	vector<vector<int>> generateMatrix(int n) {
		vector<vector<int>>res(n, vector<int>(n));
		int k = 1, i = 0;// k是要输出的数字，i是循环变量
		while (k <= n*n)
		{
			int j = i;
			while (j < n - i)			//1.从左到右
				res[i][j++] = k++;
			j = i + 1;		//到下一行
			while (j < n - i)			//2.从上到下
				res[j++][n - i - 1] = k++;
			j = n - i - 2;	//到左一列
			while (j > i)				//3.从右到左
				res[n - i - 1][j--] = k++;
			j = n - i - 1;	//到上一行
			while (j > i)				//4.从下到上
				res[j--][i] = k++;
			i++;
		}
		return res;
	}
};