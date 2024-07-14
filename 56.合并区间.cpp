/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size() == 0) return {};
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        // 先将第一个区间放入res中
        res.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++){
            // 如果当前区间的左端点小于等于res中最后一个区间的右端点，说明有重叠
            if(intervals[i][0] <= res.back()[1]){
                res.back()[1] = max(res.back()[1], intervals[i][1]);
            }else{
                // 没有重叠，直接加入
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};
// @lc code=end

