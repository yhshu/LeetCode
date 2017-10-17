/*
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree [3,9,20,null,null,15,7],
	3
   / \
  9  20
	/  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>>res;
		if (root == nullptr)
			return res;
		queue<TreeNode *>queue;

		queue.push(root);
		queue.push(nullptr);
		vector<int>cur_lv;
		while (!queue.empty())
		{
			TreeNode *node = queue.front();//取首元素
			queue.pop();
			if (node == nullptr)//行尾
			{
				res.push_back(cur_lv);
				cur_lv.resize(0);//清空向量 cur_lv
				if (queue.size() > 0)
					queue.push(nullptr);//标记cur的下一行行尾
			}
			else
			{
				cur_lv.push_back(node->val);
				if (node->left)queue.push(node->left);
				if (node->right)queue.push(node->right);
			}
		}
		return res;
	}
};