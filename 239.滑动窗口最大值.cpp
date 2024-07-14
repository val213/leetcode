/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            // 移除不在窗口内的元素
            if (!dq.empty() && dq.front() == i - k) {
                dq.pop_front();
            }
            // 移除所有小于当前元素的值
            while (!dq.empty() && nums[i] > nums[dq.back()]) {
                dq.pop_back();
            }
            // 添加当前元素索引
            dq.push_back(i);
            // 添加当前窗口的最大值
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};
// @lc code=end

