/*
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6
The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6
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
private:
  TreeNode *prev = nullptr;

public:
  void flatten(TreeNode *root) {
    if (root == nullptr) // 特殊情况
      return;
    // root->left接在root->right的右子结点上
    flatten(root->right);
    flatten(root->left);
    root->right = prev;
    root->left = nullptr;
    prev = root;
  }
};
