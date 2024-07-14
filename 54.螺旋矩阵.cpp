/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0,left=0,right=matrix[0].size()-1,bottom=matrix.size()-1;
        vector<int> res;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){
                res.push_back(matrix[top][i]);
            }
            for(int i=top+1;i<=bottom;i++){
                res.push_back(matrix[i][right]);
            }
            if(left<right && top<bottom){
                for(int i=right-1;i>=left;i--){
                    res.push_back(matrix[bottom][i]);
                }
                for(int i=bottom-1;i>top;i--){
                    res.push_back(matrix[i][left]);
                }
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return res;
    }
};
// @lc code=end

