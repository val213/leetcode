/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0){
            return false;
        }
        int n = matrix[0].size();
        int left = 0, right = m * n;
        while(left < right){
            int mid = left + (right - left) / 2;
            int mid_val = matrix[mid / n][mid % n];
            if(mid_val == target){
                return true;
            }else if(mid_val < target){
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return false;
    }
};
// @lc code=end

