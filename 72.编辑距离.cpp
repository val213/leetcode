/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {
        // dp[i][j]表示将 word1 的前 i 个字符转换为 word2 的前 j 个字符所需的最少操作次数。
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        // 初始化
        for (int i = 1; i <= word1.size(); i++) dp[i][0] = i;
        for (int j = 1; j <= word2.size(); j++) dp[0][j] = j;
        // 状态转移方程，从1开始
        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
// @lc code=end

