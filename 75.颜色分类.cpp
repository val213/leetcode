/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, mid = 0, right = nums.size() - 1;
        while (mid <= right) {
            if (nums[mid] == 0) {
                swap(nums[mid++], nums[left++]);
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[right--]);
            }
        }
    }
};
// @lc code=end

