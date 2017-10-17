/*
 * Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
	\
	 2
	/
   3
return [3,2,1].
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

 // 前序是根左右，修改前序算法，使其遍历根右左，再将此结果倒序，得到左右根，即后序.
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode *>stack;

		while (root != nullptr || !stack.empty())
		{
			if (root != nullptr)
			{
				stack.push(root);
				res.push_back(root->val);
				root = root->right;
			}
			else
			{
				TreeNode *top = stack.top();
				stack.pop();
				root = top->left;
			}
		}
		reverse(res.begin(), res.end());
		return res;
	}
};