/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // 递归构建左右子树
        return buildTree(nums, 0, nums.size() - 1);
    }
    TreeNode* buildTree(vector<int>& nums, int left, int right) {
        // 递归终止条件
        if (left > right) return nullptr;
        int mid = left + (right - left) / 2;
        // 根节点为中间节点
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = buildTree(nums, left, mid - 1);
        root->right = buildTree(nums, mid + 1, right);
        return root;
    }

};
// @lc code=end

