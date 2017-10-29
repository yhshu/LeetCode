/*
 * Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.

Example:

Input:

   1
	\
	 3
	/
   2

Output:
1

Explanation:
The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
 */

 /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define MAX 2147483647
class Solution {
public:
	int getMinimumDifference(TreeNode* root) {
		if (!root || (!root->left && !root->right))
			return 0;
		stack<TreeNode *>stack;
		TreeNode *cur = root;

		while (!stack.empty() || cur)//栈非空或者cur非空
		{
			if (cur)//cur非空，压栈，中序遍历取左子结点
			{
				stack.push(cur);
				cur = cur->left;
			}
			else//cur为空，栈非空，弹栈
			{
				TreeNode *top = stack.top();
				compute_diff(top->val);
				stack.pop();
				cur = top->right;
			}
		}
		return diff;
	}

	void compute_diff(int val)
	{
		if (prev_val == -1)
		{
			prev_val = val;
			return;
		}
		if (abs(prev_val - val) < diff)
			diff = abs(prev_val - val);
		prev_val = val;
	}

	int diff = MAX;
	int prev_val = -1;
};