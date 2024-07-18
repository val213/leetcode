/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int left = 0, right = nums.size() - 1;
        while(left<right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                return mid;
            }
            // 说明左半部分是有序的
            if(nums[left] <= nums[mid]){
                // target在左半部分，mid的左边
                if(nums[left] <= target && target < nums[mid]){
                    right = mid - 1;
                }else{
                    // target在右半部分，mid的右边
                    left = mid + 1;
                }
            }else{
                // 说明右半部分是有序的
                // target在右半部分，mid的右边
                if(nums[mid] < target && target <= nums[right]){
                    left = mid + 1;
                }else{
                    // target在左半部分，mid的左边
                    right = mid - 1;
                }
            }
        }
        return nums[left] == target ? left : -1;
    }
};
// @lc code=end

