/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        int left = 0, right = 0;
        string path;
        backtrack(n, left, right, path, res);
        return res;
    }
    void backtrack(int n, int left, int right, string path, vector<string>& res) {
        // 递归终止条件, 当左右括号数量都等于 n 时，说明已经找到了一个合法的括号组合
        if (left == n && right == n) {
            res.push_back(path);
            return;
        }
        // 当左括号数量小于 n 时，可以继续添加左括号
        if (left < n) {
            path.push_back('(');
            backtrack(n, left + 1, right, path, res);
            path.pop_back();
        }
        // 当右括号数量小于左括号数量时，可以继续添加右括号
        if (right < left) {
            path.push_back(')');
            backtrack(n, left, right + 1, path, res);
            path.pop_back();
        }
    }
};
// @lc code=end

