/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        // path: 记录当前路径
        vector<int> path;
        // used: 记录当前节点是否已经被访问
        vector<bool> used(nums.size(), false);
        dfs(nums, 0, path, used, res);
        return res;
    }
    void dfs(vector<int>& nums, int depth, vector<int>& path, vector<bool>& used, vector<vector<int>>& res) {
        // 递归终止条件, 当路径长度等于数组长度时，说明已经找到了一个全排列
        if (depth == nums.size()) {
            res.push_back(path);
            return;
        }
        // 遍历数组，找到一个未被访问的节点，将其加入路径中
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            path.push_back(nums[i]);
            // 加入当前路径后，标记当前节点已经被访问
            used[i] = true;
            // 递归下一层
            dfs(nums, depth + 1, path, used, res);
            // 回溯：返回后，将当前节点从路径中移除，并标记为未被访问
            path.pop_back();
            used[i] = false;
            // 继续遍历下一个未被访问的节点
        }
    }
};
// @lc code=end

