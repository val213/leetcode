/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        int left = 0, right = height.size() - 1;
        int left_max = 0, right_max = 0;
        while (left < right) {
        left_max = max(left_max, height[left]);
        right_max = max(right_max, height[right]);
        if (left_max < right_max) {
            sum += left_max - height[left];
            left++;
        } else {
            sum += right_max - height[right];
            right--;
        }
        }
        return sum;
    }
};
// @lc code=end

