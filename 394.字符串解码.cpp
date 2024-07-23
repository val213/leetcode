/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    string decodeString(string s) {
        stack<int> counts; // 用于存储数字
        stack<string> strings; // 用于存储字符串
        string curr = ""; // 当前正在构建的字符串
        int num = 0; // 当前的数字

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '[') {
                counts.push(num);
                strings.push(curr);
                curr = ""; // 重置当前字符串
                num = 0; // 重置当前数字
            } else if (c == ']') {
                string tmp = curr;
                curr = strings.top(); strings.pop();
                int count = counts.top(); counts.pop();
                for (int i = 0; i < count; i++) {
                    curr += tmp;
                }
            } else {
                curr += c;
            }
        }

        return curr;
    }
};
// @lc code=end

