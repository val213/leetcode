/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // 预处理，填充dp数组
        for (int right = 0; right < n; ++right) {
            for (int left = 0; left <= right; ++left) {
                if (s[left] == s[right] && (right - left <= 2 || dp[left + 1][right - 1])) {
                    dp[left][right] = true;
                }
            }
        }
        vector<vector<string>> res;
        vector<string> current;
        backtrack(s, 0, current, res, dp);
        return res;
    }

    void backtrack(const string& s, int start, vector<string>& current, vector<vector<string>>& res, const vector<vector<bool>>& dp) {
        if (start == s.size()) {
            res.push_back(current);
            return;
        }
        for (int i = start; i < s.size(); i++) {
            if (dp[start][i]) {
                current.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1, current, res, dp);
                current.pop_back();
            }
        }
    }
};
// @lc code=end

