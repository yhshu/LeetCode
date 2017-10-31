/*
 * Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.

Example 1:
Input:
	3
   / \
  9  20
	/  \
   15   7
Output: [3, 14.5, 11]
Explanation:
The average value of nodes on level 0 is 3,  on level 1 is 14.5, and on level 2 is 11. Hence return [3, 14.5, 11].
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
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double>res;
		if (!root)
			return res;
		queue<TreeNode*>queue;
		queue.push(root);
		queue.push(nullptr);
		double cur_ave = 0.0;
		int cur_cnt = 0;
		while (!queue.empty())
		{
			TreeNode *node = queue.front();
			queue.pop();
			if (node == nullptr)
			{
				cur_ave /= cur_cnt;
				res.push_back(cur_ave);
				if (queue.size() > 0)
					queue.push(nullptr);
				cur_cnt = 0;
				cur_ave = 0.0;
			}
			else
			{
				cur_ave += node->val;
				cur_cnt++;
				if (node->left)
					queue.push(node->left);
				if (node->right)
					queue.push(node->right);
			}
		}
		return res;
	}
};