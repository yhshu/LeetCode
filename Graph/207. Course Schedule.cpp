/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.

 Hints:
This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
Topological sort could also be done via BFS.
 */

// 问题等价于判断有向图中是否有环；如果有环，不存在拓扑排序的可能
// 拓扑排序可以通过DFS或BFS实现

// numCourses是课程编号，prerequisites是课程先修关系
class Solution {
public:
    bool canFinish(int numCourses, vector <pair<int, int>> &prerequisites) {
        vector <unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        // 避免使用vector<bool>
        bool vis[numCourses] = {}; // 记录所有已访问过的顶点
        bool onpath[numCourses] = {}; // 记录当前DFS访问过的顶点
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i] && DFS(graph, i, onpath, vis))
                return false; // 有环
            // else (vis[i]) continue; 之前遍历过的点不在环中
        }
        return true; // 无环
    }

    vector <unordered_set<int>> make_graph(int numCourses, vector <pair<int, int>> &prerequisites) {
        vector <unordered_set<int>> graph(numCourses); // 每门课的先修课集合
        for (auto pre:prerequisites) {
            graph[pre.second].insert(pre.first); // pre.first 是 pre.second 的先修课
        }
        return graph;
    }

    bool DFS(vector <unordered_set<int>> &graph, int node, bool onpath[], bool vis[]) {
        // 如果检测到环，返回true
        if (vis[node])return false; // 之前遍历过的点不在环中，因为一旦有环就将返回结果
        onpath[node] = vis[node] = true;
        for (int nei:graph[node]) {
            if (onpath[nei] || DFS(graph, nei, onpath, vis))
                // onpath[nei]为真，说明node处于环中；DFS(nei)为真，说明nei处于环中
                return true;
        }
        return onpath[node] = false; // 赋值，返回true
    }
};