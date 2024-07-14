/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty()) return nullptr;
        // 从前序遍历的第一个节点找到根节点
        TreeNode* root = new TreeNode(preorder[0]);
        // 在中序遍历中找到根节点的位置，得到左右子树的节点数量
        int rootIndex = 0;
        for (int i = 0; i < inorder.size(); i++) {
            if (inorder[i] == preorder[0]) {
                rootIndex = i;
                break;
            }
        }
        // 递归构建左右子树
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + rootIndex);
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootIndex);
        root->left = buildTree(leftPreorder, leftInorder);
        vector<int> rightPreorder(preorder.begin() + 1 + rootIndex, preorder.end());
        vector<int> rightInorder(inorder.begin() + rootIndex + 1, inorder.end());
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};
// @lc code=end

