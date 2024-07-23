/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> buckets(20001, 0); // 使用vector初始化20001个桶，初始计数为0
        for (int num : nums) {
            buckets[num + 10000]++; // 计数
        }
        for (int i = 20000; i >= 0; i--) {
            k -= buckets[i];
            if (k <= 0) {
                return i - 10000;
            }
        }
        return 0;
    }
};
// @lc code=end

