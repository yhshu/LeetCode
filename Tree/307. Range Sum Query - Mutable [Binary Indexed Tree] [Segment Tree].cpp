/*
Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

The update(i, val) function modifies nums by updating the element at index i to val.

Example:

Given nums = [1, 3, 5]

sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8
Note:

The array is only modifiable by the update function.
You may assume the number of calls to update and sumRange function is distributed evenly.
*/

class NumArray {
public:
    class SegmentTreeNode {
    public:
        int s, e;
        SegmentTreeNode *left, *right;
        int sum;

        SegmentTreeNode(int s, int e) :
                s(s), e(e), left(nullptr), right(nullptr), sum(0) {
        }

        ~SegmentTreeNode() {
            if (this->left != nullptr)
                delete (this->left);
            if (this->right != nullptr)
                delete (this->right);
            delete this;
        }
    };

    SegmentTreeNode *root = nullptr;

    NumArray(vector<int> nums) {
        root = buildTree(nums, 0, nums.size() - 1);
    }

    SegmentTreeNode *buildTree(vector<int> nums, int s, int e) {
        if (s > e)
            return nullptr;
        SegmentTreeNode *ret = new SegmentTreeNode(s, e);
        if (s == e) {
            ret->sum = nums[s];
        } else {
            int mid = s + (e - s) / 2; // 中位
            ret->left = buildTree(nums, s, mid);
            ret->right = buildTree(nums, mid + 1, e);
            ret->sum = ret->left->sum + ret->right->sum;
        }
        return ret;
    }

    void update(int i, int val) {
        update(root, i, val);
    }

    void update(SegmentTreeNode *root, int pos, int val) {
        if (root->s == root->e) // 线段树只有一个数
            root->sum = val;
        else {
            int mid = root->s + (root->e - root->s) / 2; // 线段树中位
            if (pos <= mid) // 注意等号
                update(root->left, pos, val); // 左子树中更新
            else update(root->right, pos, val); // 右子树中更新
            root->sum = root->left->sum + root->right->sum; // 更新各层结点sum
        }
    }

    int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }

    int sumRange(SegmentTreeNode *root, int i, int j) {
        if (root->e == j && root->s == i) // 线段树只有一个数
            return root->sum;
        else {
            int mid = root->s + (root->e - root->s) / 2; // 线段树中位
            if (mid >= j) // 注意等号
                return sumRange(root->left, i, j); // 左子树中求和
            else if (mid < i)
                return sumRange(root->right, i, j); // 右子树中求和
            else return sumRange(root->left, i, mid) + sumRange(root->right, mid + 1, j);
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */