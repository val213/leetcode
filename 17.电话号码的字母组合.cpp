/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> phoneMap = {
            {'2', "abc"}, {'3', "def"},
            {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"},
            {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> res;
        if (digits.empty()) return res;
        string path;
        backtrack(digits, 0, phoneMap, path, res);
        return res;
    }
    void backtrack(string& digits, int depth, unordered_map<char, string>& phoneMap, string& path, vector<string>& res) {
        // 递归终止条件, 当路径长度等于数组长度时，说明已经找到了一个组合
        if (depth == digits.size()) {
            res.push_back(path);
            return;
        }
        // 遍历当前数字对应的所有字母
        for (char& c : phoneMap[digits[depth]]) {
            path.push_back(c);
            // 递归下一层
            backtrack(digits, depth + 1, phoneMap, path, res);
            // 回溯：返回后，将当前节点从路径中移除
            path.pop_back();
        }
    }
};
// @lc code=end

