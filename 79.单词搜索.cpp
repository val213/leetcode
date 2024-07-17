/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // 从起始字母开始搜索
                if (board[i][j]==word[0] && backtrack(board, word, i, j, 0)) return true;
            }
        }
        return false;
    }
    bool backtrack(vector<vector<char>>& board, string word, int i, int j, int depth){
        // 递归终止条件，当深度等于单词长度时，说明已经找到了目标单词
        if (depth == word.size()) return true;
        // 递归终止条件，当越界或当前字母不等于目标字母时，返回 false
        if (i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j]!=word[depth]) return false;
        // 标记当前字母已经被访问过
        char temp = board[i][j];
        board[i][j] = '0';
        bool res = backtrack(board, word, i+1, j, depth+1) || backtrack(board, word, i-1, j, depth+1) || backtrack(board, word, i, j+1, depth+1) || backtrack(board, word, i, j-1, depth+1);
        // 回溯：恢复当前字母
        board[i][j] = temp;
        return res;
    }
};
// @lc code=end

