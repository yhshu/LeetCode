/*
 *Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).

Example:

root = [5,3,6,2,4,null,7]
key = 3

	5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.

One valid answer is [5,4,6,2,null,null,7], shown in the following BST.

	5
   / \
  4   6
 /     \
2       7

Another valid answer is [5,2,6,null,4,null,7].

	5
   / \
  2   6
   \   \
	4   7
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
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr)
			return nullptr;
		if (key < root->val)
			root->left = deleteNode(root->left, key); // 在左子树中删除
		else if (key > root->val)
			root->right = deleteNode(root->right, key); // 在右子树中删除
		else// if(key == root->val) 删除root
		{
			// 如果root仅有一个子结点，其子结点替换root；如果root是叶结点，直接删除
			if (root->left == nullptr)
				return root->right;
			else if (root->right == nullptr)
				return root->left;
			// 如果root有两个子结点
			TreeNode *minNode = Mini(root->right); // minNode是root的后继
			root->val = minNode->val;
			root->right = deleteNode(root->right, root->val); // 递归删除后继
		}
		return root;
	}

	TreeNode *Mini(TreeNode *x)
	{
		while (x->left != nullptr)
			x = x->left;
		return x;
	}
};