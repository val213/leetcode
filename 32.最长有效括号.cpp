/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */

// @lc code=start
# include <string>
# include <vector>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0) return 0;
        // dp[i]表示以s[i]结尾的最长有效括号的长度
        vector<int> dp(s.size(), 0);
        int res = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + (i - dp[i - 1] >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};
// @lc code=end

