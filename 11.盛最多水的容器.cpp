/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int left = 0, right = height.size() - 1;
        while (left<right){
            int area = (right - left) * min(height[left], height[right]);
            max_area = max(max_area, area);
            if (height[left] < height[right]){
                left++;
            } else {
                right--;
            }
        }
        return max_area;
    }
};
// @lc code=end

