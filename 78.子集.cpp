/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current; 
        vector<vector<int>> res;
        backtrack(nums, 0, current, res);
        return res;
    }
    void backtrack(vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& res) {
        res.push_back(current);
        for (int i = start; i<nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(nums, i+1, current, res);
            current.pop_back();
        }
    }
};
// @lc code=end

