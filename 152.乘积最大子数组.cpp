/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        // dp_max[i]表示以nums[i]结尾的乘积最大子数组的乘积
        vector<double> dp_max(nums.size(), 0);
        // dp_min[i]表示以nums[i]结尾的乘积最小子数组的乘积
        vector<double> dp_min(nums.size(), 0);
        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        double res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp_max[i] = max(max(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]), static_cast<double>(nums[i]));
            dp_min[i] = min(min(dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]), static_cast<double>(nums[i]));
            res = max(res, dp_max[i]);
        }
        return res;
        
    }
};
// @lc code=end

