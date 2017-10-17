/*
 Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree [1,null,2,3],
   1
	\
	 2
	/
   3
return [1,3,2].
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
	vector<int> inorderTraversal(TreeNode* root) {//中序遍历
		vector<int> res;
		stack<TreeNode * >stack;
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
				res.push_back(top->val);
				stack.pop();
				cur = top->right;
			}
		}
		return res;
	}
};