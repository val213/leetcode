/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 */

// @lc code=start
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    int time = 0;
    int fresh = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 2) {
                q.push({i, j});
            } else if (grid[i][j] == 1) {
                fresh++;
            }
        }
    }
    if (fresh == 0) return 0; // 如果没有新鲜橘子，直接返回0
    // 方向数组，用于遍历上下左右四个方向
    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto [x, y] = q.front(); q.pop();
            for (auto [dx, dy] : directions) {
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1) {
                    grid[nx][ny] = 2;
                    q.push({nx, ny});
                    fresh--;
                }
            }
        }
        time++;
    }
    return fresh == 0 ? time - 1 : -1; // 如果还有新鲜橘子，返回-1，否则返回正确的时间
    }
};
// @lc code=end

