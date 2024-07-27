/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        // dp[i][j]表示s[i, j]是否是回文串
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        int start = 0, maxLen = 1;
        // 初始化长度为1的回文串
        for (int i = 0; i < n; i++) dp[i][i] = 1;
        // 初始化长度为2的回文串
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                start = i;
                maxLen = 2;
            }
        }
        // 状态转移方程
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                    start = i;
                    maxLen = len;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};
// @lc code=end

