/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int pathSum(TreeNode* root, long targetSum) {
        // 前缀和-路径数
        unordered_map<long, long> prefixSumCount;
        prefixSumCount[0] = 1; // 前缀和为0的路径有1条
        return helper(root, 0, targetSum, prefixSumCount);
    }

private:
    int helper(TreeNode* node, long currentSum, long targetSum, unordered_map<long, long>& prefixSumCount) {
        if (!node) return 0;
        // 当前路径和
        currentSum += node->val;
        // 当前路径和减去目标值的路径数
        int numPathsToCurr = prefixSumCount[currentSum - targetSum]; // 当前前缀和减去目标值的路径数
        prefixSumCount[currentSum]++; // 更新当前路径和

        // 递归遍历左右子树
        int result = numPathsToCurr + helper(node->left, currentSum, targetSum, prefixSumCount) + helper(node->right, currentSum, targetSum, prefixSumCount);
    
        prefixSumCount[currentSum]--; // 回溯，恢复状态
        return result;
    }
};
// @lc code=end

