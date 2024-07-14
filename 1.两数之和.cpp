/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> hash_map;
        for (int i = 0; i < nums.size(); i++) {
            if (hash_map.find(target - nums[i]) != hash_map.end()) {
                return {hash_map[target - nums[i]], i};
            }
            hash_map[nums[i]] = i;
        }
        return {}; 

    }
};
// @lc code=end

