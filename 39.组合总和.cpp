/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> current;
        vector<vector<int>> res;
        backtrack(candidates, target, 0, current, res);
        return res;
    }
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& res) {
        // 每一次回溯把 target 减去选中的数，当 target 小于 0 时，说明当前路径不合法，直接返回
        if (target < 0) return;
        // 当 target 等于 0 时，说明找到了一个合法的路径，将其加入结果集
        if (target == 0) {
            res.push_back(current);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            // 由于每个数字可以被重复选取，所以从当前数字开始继续遍历
            current.push_back(candidates[i]);
            // 递归下一层，由于每个数字可以被重复选取，所以传入的 start 为 i
            backtrack(candidates, target - candidates[i], i, current, res);
            // 回溯：返回后，将当前节点从路径中移除
            current.pop_back();
        }
    }
};
// @lc code=end

