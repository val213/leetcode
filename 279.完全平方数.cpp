/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <vector>   
#include <algorithm>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        // dp[i]表示i的最少完全平方数的个数
        vector<int> dp(n + 1, INT_MAX);
        // 初始化
        dp[0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                // 状态转移方程
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }
        return dp[n];

    }
};
// @lc code=end

