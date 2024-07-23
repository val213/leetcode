/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        // 初始化跳跃次数，当前能跳到的最远位置，下一次能跳到的最远位置
        int jumps = 0, currenEnd = 0, nextEnd = 0;
        // 最后一个元素不需要跳跃，所以不用遍历到最后一个元素
        for (int i = 0; i < nums.size() - 1; ++i) {
            // 更新下一次能跳到的最远位置
            nextEnd = max(nextEnd, i + nums[i]);
            // 如果当前位置是当前能跳到的最远位置，说明需要再跳一次
            if (i == currenEnd) {
                // 更新当前能跳到的最远位置
                currenEnd = nextEnd;
                ++jumps;
            }
        }
        return jumps;
    }
};
// @lc code=end

