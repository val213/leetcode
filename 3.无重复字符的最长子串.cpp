/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0, right = 0;
        int res = 0;
        unordered_map<char, int> window;
        while (right < s.size()) {
            char c = s[right];
            right++;
            window[c]++;
            while (window[c] > 1) {
                char d = s[left];
                left++;
                window[d]--;
            }
            res = max(res, right - left);
        }    
        return res;
    }
};
// @lc code=end

