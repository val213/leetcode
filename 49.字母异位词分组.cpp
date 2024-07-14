/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashmap;
        // 每个单词进行排序作为hashmap的key
        for (string str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            hashmap[key].push_back(str);
        }
        // 对于strs的每一个单词，找到其对应的key，然后将其放入对应的vector中
        vector<vector<string>> res;
        for (auto it = hashmap.begin(); it != hashmap.end(); it++) {
            res.push_back(it->second);
        }
        return res;

    }
};
// @lc code=end

