/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> window,need;
        int start = 0, len = INT_MAX; // 用于记录最小覆盖子串的起始位置和长度
        int valid = 0; // 记录窗口中满足 need 条件的字符个数
        string res;
        for (char c:t){
            need[c]++;
        }
        int left=0,right=0;
        while(right<s.size()){
            char c=s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) valid++;
            }
            // 收缩窗口
            while (valid == need.size()) {
                // 更新最小覆盖子串
                if (right - left < len) {
                    start = left;
                    len = right - left;
                }
                // 左边界右移
                char d = s[left];
                left++;
                // 如果 d 在 need 中，更新valid
                if (need.count(d)) {
                    if (window[d] == need[d]) valid--;
                    window[d]--;
                }
            }
        }
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};
// @lc code=end


