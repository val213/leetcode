/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> res;
        backtrack(board, 0, res);
        return res;
    }
    void backtrack(vector<string>& board, int row, vector<vector<string>>& res) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < board.size(); col++) {
            // 排除不合法选择
            if (!isValid(board, row, col)) continue;
            // 放置皇后
            board[row][col] = 'Q';
            // 进入下一行决策
            backtrack(board, row + 1, res);
            // 撤销放置
            board[row][col] = '.';
        }
    }
    bool isValid(vector<string>& board, int row, int col) {
        // 检查列是否有皇后互相冲突
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        // 检查右上方是否有皇后互相冲突
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        // 检查左上方是否有皇后互相冲突
        for (int i = row - 1, j = col + 1; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }
};
// @lc code=end

