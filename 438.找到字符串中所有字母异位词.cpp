/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> need, window;
        for (char c : p) need[c]++;
        int left = 0, right = 0;
        while (right < s.size()) {
            char c = s[right];
            right++;
            window[c]++;
            while (window[c] > need[c]) {
                char d = s[left];
                left++;
                window[d]--;
            }
            if (right - left == p.size()) res.push_back(left);
        }
        return res;
    }
};
// @lc code=end

