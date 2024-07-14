/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); i++){
            // 去重
            if(i > 0 && nums[i] == nums[i-1]){
                continue;
            }
            // 转换为两数之和双指针问题
            int left = i + 1, right = nums.size() - 1;
            int target = -nums[i];
            while(left < right){
                if(nums[left] + nums[right] == target){
                    res.push_back({nums[i], nums[left], nums[right]});
                    // 去重
                    while(left < right && nums[left] == nums[left+1]){
                        left++;
                    }
                    while(left < right && nums[right] == nums[right-1]){
                        right--;
                    }
                    left++;
                    right--;
                } else if(nums[left] + nums[right] < target){
                    left++;
                } else {
                    right--;
                }
            }
    }
    return res;
    }
};
// @lc code=end

