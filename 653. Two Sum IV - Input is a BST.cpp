/*
 * Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.

Example 1:
Input:
	5
   / \
  3   6
 / \   \
2   4   7

Target = 9

Output: True
Example 2:
Input:
	5
   / \
  3   6
 / \   \
2   4   7

Target = 28

Output: False

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
	int prev_val = -1;
	bool findTarget(TreeNode* root, int k) {
		if (!root->left && !root->right)
			return false;
		stack<TreeNode*>stack;
		unordered_map<int, bool>map;
		TreeNode *cur = root;
		while (!stack.empty() || cur)
		{
			if (cur)
			{
				stack.push(cur);
				cur = cur->left;
			}
			else
			{
				TreeNode *top = stack.top();
				stack.pop();
				cur = top->right;
				map[top->val] = true;
				if (map[k - top->val] && k != 2 * top->val)
					return true;
			}
		}
		return false;
	}
};