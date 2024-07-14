/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return isMirror(root->left, root->right);
    }

private:
    bool isMirror(TreeNode* left, TreeNode* right) {
        // 如果左右子树都为空，则对称
        if (!left && !right) return true;
        // 如果左右子树仅有一个为空，或者两者的值不相等，则不对称
        if (!left || !right || left->val != right->val) return false;
        // 递归比较左子树的左孩子和右子树的右孩子，以及左子树的右孩子和右子树的左孩子
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};
// @lc code=end

