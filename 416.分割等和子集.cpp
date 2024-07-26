/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        // dp[i][j]表示前i个数中是否可以找到和为j的子集
        int sum = 0;
        int len = nums.size();
        // 计算总和
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        // 如果总和是奇数，直接返回false
        if (sum % 2 != 0) return false;
        vector<vector<bool>> dp(len, vector<bool>(sum/2 + 1, false));
        for (int i = 0; i < len; i++) {
            dp[i][0] = true; // 和为0总是可能的
        }
        // 如果第一个元素小于等于sum/2，那么只使用第一个元素就可以得到和为nums[0]的子集
        if (nums[0] <= sum / 2) dp[0][nums[0]] = true; // 只使用第一个元素
        for (int i = 1; i < len; i++) {
            for (int j = 0; j <= sum/2; j++) {
                // 如果不使用第i个元素，那么dp[i][j] = dp[i-1][j]
                dp[i][j] = dp[i-1][j];
                // 如果使用第i个元素，那么dp[i][j] = dp[i-1][j-nums[i]]
                if (j >= nums[i]) {
                    dp[i][j] = dp[i][j] || dp[i-1][j-nums[i]];
                }
                if (dp[i-1][sum/2]) return true;
            }
        }
        return dp[len-1][sum/2];
    }
};
// @lc code=end

