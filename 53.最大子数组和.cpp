/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> prefixsum(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            prefixsum[i] = prefixsum[i - 1] + nums[i - 1];
        }
        int maxprefixsum = nums[0]; // 初始化为nums[0]以正确处理全负数数组
        int minprefixsum = 0;
        int maxSubArraySum = nums[0]; // 添加一个变量来跟踪最大子数组和
        for (int i = 1; i <= nums.size(); i++) {
            maxSubArraySum = max(maxSubArraySum, prefixsum[i] - minprefixsum);
            minprefixsum = min(minprefixsum, prefixsum[i]);
        }
        return maxSubArraySum;
}
};
// @lc code=end

