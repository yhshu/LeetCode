/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
 */

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> res = new ArrayList<String>();
        if (root == null)
            return res;
        binaryTreePaths(res, root, "");
        return res;
    }

    public void binaryTreePaths(List<String> res, TreeNode root, String str) {
        if (root.left == null && root.right == null)
            res.add(str + root.val);
        if (root.left != null)
            binaryTreePaths(res, root.left, str + root.val + "->");
        if (root.right != null)
            binaryTreePaths(res, root.right, str + root.val + "->");
    }
}