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
    int findBottomLeftValue(TreeNode *root) {
        queue <TreeNode *> queue;
        queue.push(root);
        queue.push(nullptr);
        int res;
        bool noChild = true;
        bool firstElem = true;
        while (!queue.empty()) {
            TreeNode *node = queue.front();//取首元素
            queue.pop();
            if (node == nullptr)//行尾
            {
                if (noChild)
                    return res;
                else {
                    noChild = true;
                    firstElem = true;
                }
                if (queue.size() > 0)
                    queue.push(nullptr);//标记cur的下一行行尾
            } else {
                if (firstElem) {
                    res = node->val;
                    firstElem = false;
                }
                if (node->left) {
                    noChild = false;
                    queue.push(node->left);
                }
                if (node->right) {
                    noChild = false;
                    queue.push(node->right);
                }
            }
        }
    }
};