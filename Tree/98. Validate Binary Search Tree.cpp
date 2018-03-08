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
    bool isValidBST(TreeNode *root) {
        /*
         *  BST 满足以下四条性质：
         a. 若左子树非空，则左子树上的所有结点的关键字均小于根结点的关键字
         b. 若右子树非空，则右子树上的所有结点的关键字均大于根结点的关键字
         c. 左右子树本身也分别是二叉搜索树
         d. 没有键值相等的结点，这不同于堆（heap）
         */
        return isValidBST(root, nullptr, nullptr);
    }

    bool isValidBST(TreeNode *root, TreeNode *minNode, TreeNode *maxNode) {
        if (!root) return true;
        if (minNode && root->val <= minNode->val || maxNode && root->val >= maxNode->val)
            return false;
        return isValidBST(root->left, minNode, root) && isValidBST(root->right, root, maxNode);
    }
};