/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int num = 0;
        int sum = 0;
        // 计算前缀和
        unordered_map<int, int> map;
        map[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (map.find(sum - k) != map.end()) {
                num += map[sum - k];
            }
            map[sum]++;
        }
        return num;
    }
};
// @lc code=end

