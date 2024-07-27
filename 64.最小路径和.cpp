/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // dp[i][j]表示从(0, 0)到(i, j)的最小路径和
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), 0));
        // 先初始化左上角的最小路径和
        dp[0][0] = grid[0][0];
        // 初始化左边界的最小路径和
        for (int i = 1; i < grid.size(); i++) dp[i][0] = dp[i - 1][0] + grid[i][0];
        // 初始化上边界的最小路径和
        for (int j = 1; j < grid[0].size(); j++) dp[0][j] = dp[0][j - 1] + grid[0][j];
        // 状态转移方程
        for (int i = 1; i < grid.size(); i++) 
            for (int j = 1; j < grid[0].size(); j++) 
                // 从左边或上边过来的最小路径和，多了一次比较
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
        return dp[grid.size() - 1][grid[0].size() - 1];
    }
};
// @lc code=end

