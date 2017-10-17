/*
 *Invert a binary tree.

	 4
   /   \
  2     7
 / \   / \
1   3 6   9
to
	 4
   /   \
  7     2
 / \   / \
9   6 3   1
 */
 
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 
func invertTree(root *TreeNode) *TreeNode {
	if root != nil {
		if root.Left != nil {
			right := root.Right
			root.Right = root.Left
			root.Left = right
		} else if root.Right != nil {
			root.Left = root.Right
			root.Right = nil
		}
		invertTree(root.Left)
		invertTree(root.Right)
	}
	return root
}