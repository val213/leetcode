/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i]表示s[0:i]是否可以被拆分
        vector<bool> dp(s.size() + 1, false);
        // 初始化
        dp[0] = true;
        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                // 如果s[0:j]可以被拆分，且s[j:i]在字典中
                if (dp[j] && find(wordDict.begin(), wordDict.end(), s.substr(j, i - j)) != wordDict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

