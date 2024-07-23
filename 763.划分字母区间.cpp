/*
 * @lc app=leetcode.cn id=763 lang=cpp
 *
 * [763] 划分字母区间
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> partitionLabels(string s) {
        // 记录每个字符最后出现的位置
        vector<int> last(26, 0);
        for (int i = 0; i < s.size(); ++i) {
            last[s[i] - 'a'] = i;
        }
        int start = 0, end = 0;
        vector<int> res;
        // 遍历字符串
        for (int i = 0; i < s.size(); ++i) {
            // 更新当前区间的最远位置
            end = max(end, last[s[i] - 'a']);
            // 如果当前位置是当前区间的最远位置
            if (i == end) {
                // 计算区间长度
                res.push_back(end - start + 1);
                // 更新下一个区间的起始位置
                start = end + 1;
            }
        }
        return res;
    }
};
// @lc code=end

