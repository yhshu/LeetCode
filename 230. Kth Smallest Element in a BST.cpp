/*
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ¡Ü k ¡Ü BST's total elements.

Follow up:
What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
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
	int cnt = 0;
	int kthSmallest(TreeNode* root, int k) {
		stack<TreeNode *>stack;
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
				if (++cnt == k)
					return top->val;
				cur = top->right;
			}
		}
	}
};