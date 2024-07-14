/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
        int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hashmap;
        int res = 0;
        for (int num : nums) {
            if (!hashmap[num]) { // 如果num未被处理过
                int left = hashmap[num - 1];
                int right = hashmap[num + 1];
                int sum = left + right + 1;
                hashmap[num] = sum;
                hashmap[num - left] = sum;
                hashmap[num + right] = sum;
                res = max(res, sum);
            }
        }
        return res;
    }
};
// @lc code=end

