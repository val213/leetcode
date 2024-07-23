/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i]表示凑成金额i所需的最少硬币数
        vector<int> dp(amount + 1, -1);
        // 初始化硬币本身的数量为1
        for (int i = 0; i < coins.size(); i++) {
            if (coins[i] <= amount) {
                dp[coins[i]] = 1;
            }
        }
        dp[0] = 0;
        // 从1开始递推
        for (int i = 1; i <= amount; i++){
            for (int j = 0; j < coins.size(); j++) {
                // 如果i-coins[j] >= 0，说明可以用coins[j]这个硬币;
                // dp[i - coins[j]] != -1，说明i - coins[j]这个金额是可以被凑成的
                if (i-coins[j] >= 0 && dp[i - coins[j]] != -1) {
                    if (dp[i] == -1) {
                        // 如果dp[i]还没有被赋值过，直接赋值
                        dp[i] = dp[i - coins[j]] + 1;
                    } else {
                        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                    }
                }
            }
        }
        return dp[amount];
    }
};
// @lc code=end

