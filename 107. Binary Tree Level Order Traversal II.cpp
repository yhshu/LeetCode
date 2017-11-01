/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
3
/ \
9  20
/  \
15   7
return its bottom-up level order traversal as:
[
[15,7],
[9,20],
[3]
]*/

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
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>>res;
		if (!root)
			return res;
		queue<TreeNode *>queue;
		queue.push(root);
		queue.push(nullptr);
		vector<int>cur_lev;
		TreeNode *cur;
		while (!queue.empty() || cur)
		{
			cur = queue.front();
			queue.pop();
			if (cur == nullptr)
			{
				res.push_back(cur_lev);
				cur_lev.clear();
				if (queue.size() > 0)
					queue.push(nullptr);
			}
			else
			{
				cur_lev.push_back(cur->val);
				if (cur->left)
					queue.push(cur->left);
				if (cur->right)
					queue.push(cur->right);
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
};