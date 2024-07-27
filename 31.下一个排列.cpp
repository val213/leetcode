/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        // 从右往左找到第一个递减的数
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) i--;
        // 如果找到了递减的数，再从右往左找到第一个比它大的数
        if (i >= 0) {
            int j = nums.size() - 1;
            while (j >= 0 && nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);
        }
        // 反转递减的数右边的数，变成递增的也是最小的序列；同时也能处理边界条件
        reverse(nums.begin() + i + 1, nums.end());
    }
};
// @lc code=end

