/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 入度表
        vector<int> indegrees(numCourses, 0);
        // 邻接表
        vector<vector<int>> adjacency(numCourses);
        // 队列，存储所有入度为0的节点
        queue<int> q;
        // 构建图并计算所有节点的入度
        for (auto& pre : prerequisites) {
            indegrees[pre[0]]++;
            adjacency[pre[1]].push_back(pre[0]);
        }
        // 将所有入度为0的节点入队
        for (int i = 0; i < numCourses; ++i) {
            if (indegrees[i] == 0) q.push(i);
        }
        // 拓扑排序
        while (!q.empty()) {
            int pre = q.front();
            q.pop();
            numCourses--;
            for (int& course : adjacency[pre]) {
                if (--indegrees[course] == 0) q.push(course);
            }
        }
        return numCourses == 0;
    }
};
// @lc code=end

