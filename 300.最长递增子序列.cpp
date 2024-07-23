/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    // 常规dp
    //     // dp[i]表示以nums[0:i]中最长递增子序列的长度
    //     vector<int> dp(nums.size(), 1);
    //     for (int i = 0; i < nums.size(); i++){
    //         for (int j = 0; j < i; j++) {
    //             if (nums[j] < nums[i]) {
    //                 dp[i] = max(dp[i], dp[j] + 1);
    //             }
    //         }
    //     }
    //     return *max_element(dp.begin(), dp.end());

    // 二分查找优化
    // tails[i]表示长度为i+1的最长递增子序列的最后一个数
    vector<int> tails(nums.size(), 0);
        // size 表示当前最长递增子序列的长度（本该是tails的长度）
        int size = 0;
        for (int x : nums) {
            // 对于nums中的每一个数x
            // 二分查找 tails 中第一个大于等于x的数
            int i = 0, j = size;
            while (i != j) {
                int m = (i + j) / 2;
                if (tails[m] < x)
                    i = m + 1;
                else
                    j = m;
            }
            // 更新tails，保证tails[i]是最小的（使得tails增长的最慢）并且是递增的
            tails[i] = x;
            // 如果i == size，说明x比tails中的所有数都大，size++
            if (i == size) ++size;
        }
        return size;
    }
};
// @lc code=end

