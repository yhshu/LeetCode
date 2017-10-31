/*
You need to find the largest value in each row of a binary tree.

Example:
Input:

1
/ \
3   2
/ \   \
5   3   9

Output: [1, 3, 9]
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
class Solution {
public:
	vector<int> largestValues(TreeNode* root) {
		vector<int>res;
		if (root == nullptr)
			return res;
		queue<TreeNode *>queue;

		queue.push(root);
		queue.push(nullptr);
		int cur_max = -2147483648;
		while (!queue.empty())
		{
			TreeNode *node = queue.front();
			queue.pop();
			if (node == nullptr)
			{
				res.push_back(cur_max);
				if (queue.size() > 0)
					queue.push(nullptr);
				cur_max = -2147483648;
			}
			else
			{
				if (node->val > cur_max)
					cur_max = node->val;
				if (node->left)
					queue.push(node->left);
				if (node->right)
					queue.push(node->right);
			}
		}
		return res;
	}
};