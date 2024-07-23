/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c : s){
            if (c == '(' || c == '[' || c == '{'){
                st.push(c);
            }else{
                if (st.empty()) return false;
                if (c == ')' && st.top() != '(') return false;
                if (c == ']' && st.top() != '[') return false;
                if (c == '}' && st.top() != '{') return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
// @lc code=end

