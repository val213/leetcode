/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0); // 初始化结果数组，初始值为0
        stack<int> s; // 用于存储索引的栈
        // 遍历数组，如果当前温度大于栈顶温度，则弹出栈顶元素并计算结果
        for (int i = 0; i < temperatures.size(); i++) {
            // 如果栈不为空且当前温度大于栈顶温度，则弹出栈顶元素并计算结果
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int pre = s.top(); s.pop();
                ans[pre] = i - pre;
            }
            s.push(i);
        }
        return ans;
    }
};
// @lc code=end

