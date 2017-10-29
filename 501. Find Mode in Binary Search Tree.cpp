/*
 * Given a binary search tree (BST) with duplicates, find all the mode(s) (the most frequently occurred element) in the given BST.

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than or equal to the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
For example:
Given BST [1,null,2,2],
   1
	\
	 2
	/
   2
return [2].

Note: If a tree has more than one mode, you can return them in any order.

Follow up: Could you do that without using any extra space? (Assume that the implicit stack space incurred due to recursion does not count).
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
	vector<int>res;
	int curCount = 0;
	int maxCount = 0;
	int curVal = -1;

	vector<int> findMode(TreeNode* root) {
		// inorder the BST iteratively
		if (!root)return res;
		if (!root->left && !root->right)
		{
			res.push_back(root->val);
			return res;
		}
		stack<TreeNode *>stack;
		TreeNode *cur = root;
		while (!stack.empty() || cur)//栈非空或cur非null
		{
			if (cur)//cur存在
			{
				stack.push(cur);
				cur = cur->left;
			}
			else//cur不存在，栈非空 
			{
				TreeNode *top = stack.top();
				Mode(top->val);
				stack.pop();
				cur = top->right;
			}
		}
		return res;
	}

	void Mode(int val)
	{
		if (val != curVal)
		{
			curVal = val;
			curCount = 0;
		}
		curCount++;
		if (curCount > maxCount)
		{
			maxCount = curCount;
			res.clear();
			res.push_back(curVal);
		}
		else if (curCount == maxCount)
			res.push_back(curVal);
	}
};