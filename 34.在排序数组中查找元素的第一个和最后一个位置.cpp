/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int left = 0, right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                right = mid;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        if(left == nums.size() || nums[left] != target){
            return res;
        }
        res[0] = left;
        right = nums.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target){
                left = mid + 1;
            }else if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        res[1] = left - 1;
        return res;
    }
};
// @lc code=end

