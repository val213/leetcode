/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        // 递归
        // 限定以 root 为根的子树节点必须满足 (min, max) 的限制
        // 当 root 节点的值 val 小于等于 min 或者大于等于 max 时，不满足 BST 的定义
        return validate(root, LONG_MIN, LONG_MAX);
    }
private:
    bool validate(TreeNode* root, long min, long max) {
        if (root == nullptr) return true;
        if (root->val <= min || root->val >= max) return false;
        return validate(root->left, min, root->val) && validate(root->right, root->val, max);
    }

};
// @lc code=end

