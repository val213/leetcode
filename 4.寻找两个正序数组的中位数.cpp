/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()){
            vector<int> temp = nums1;
            nums1 = nums2;
            nums2 = temp;
        }
        // 确保nums1是较短的数组，这也属于边界情况的优化
        int m = nums1.size(), n = nums2.size();
        int left = 0, right = m;
        int mid = (m + n + 1) / 2;
        while(left < right){
            int i = left + (right - left) / 2;
            int j = mid - i;
            // 判断分割线是否合理并进行调整
            if(nums1[i] < nums2[j - 1]){
                left = i + 1;
            }else{
                right = i;
            }
        }
        int i = left, j = mid - i;
        int nums1LeftMax = i == 0 ? INT_MIN : nums1[i - 1];
        int nums1RightMin = i == m ? INT_MAX : nums1[i];
        int nums2LeftMax = j == 0 ? INT_MIN : nums2[j - 1];
        int nums2RightMin = j == n ? INT_MAX : nums2[j];
        if((m + n) % 2 == 1){
            return max(nums1LeftMax, nums2LeftMax);
        }else{
            return (max(nums1LeftMax, nums2LeftMax) + min(nums1RightMin, nums2RightMin)) / 2.0;
        }        
    }
};
// @lc code=end

