/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @lc code=start
# include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[i][j]表示从(0, 0)到(i, j)的路径数
        vector<vector<int>> dp(m, vector<int>(n, 0));
        // 先初始化左、上边界的路径数
        for (int i = 0; i < m; i++) dp[i][0] = 1;
        for (int j = 0; j < n; j++) dp[0][j] = 1;
        // 状态转移方程
        for (int i = 1; i < m; i++) 
            for (int j = 1; j < n; j++) 
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m - 1][n - 1];
    }
};
// @lc code=end

