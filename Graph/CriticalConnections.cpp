//
// Created by 。 on 2024/4/17.
//
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>
#include <list>
#include <stack>
#include <climits>

using namespace std;
class Solution {
public:
    // 出入度问题?????
    // 本题没有自环用例
    // 证明:当且仅当出入度为 1 的节点的边为关键连接
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        if (n == 2) return vector<vector<int>>{{0,1}};
        unordered_map<int,vector<int>> unorderedMap;
        vector<int> inDeg(n,0);
        vector<vector<int>> ans;
        for (int i = 0; i < connections.size(); ++i) {
            unorderedMap[connections[i][0]].push_back(connections[i][1]);
            unorderedMap[connections[i][1]].push_back(connections[i][0]);
            inDeg[connections[i][0]]++;
            inDeg[connections[i][1]]++;
        }
        for (int i = 0; i < inDeg.size(); ++i) {
            if (inDeg[i] == 1){
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(unorderedMap[i][0]);
                ans.push_back(temp);
            }
        }
        return ans;
    }
};


class Solution1 {
private:
    int time = 0; // 记录DFS的次序
    vector<vector<int>> graph; // 图的邻接表表示
    vector<int> ids; // 每个节点的DFS次序
    vector<int> lows; // 每个节点能达到的最小DFS次序
    vector<vector<int>> result; // 存储关键连接的结果

    // 深度优先搜索函数，用于查找关键连接
    void dfs(int u, int parent) {
        ids[u] = lows[u] = ++time; // 初始化当前节点的DFS次序和最小DFS次序

        // 遍历当前节点的所有邻居节点
        for (int v : graph[u]) {
            if (v == parent) continue; // 忽略父节点，避免重复搜索

            // 如果邻居节点v还没有被访问过，则进行DFS
            if (ids[v] == 0) {
                dfs(v, u); // 递归调用DFS
                lows[u] = min(lows[u], lows[v]); // 更新当前节点能达到的最小DFS次序

                // 如果邻居节点v的最小DFS次序大于当前节点的DFS次序，说明(u, v)是关键连接
                if (lows[v] > ids[u]) {
                    result.push_back({u, v}); // 将关键连接添加到结果中
                }
            } else {
                lows[u] = min(lows[u], ids[v]); // 更新当前节点能达到的最小DFS次序
            }
        }
    }

public:
    // 主函数，找出关键连接
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        graph.resize(n); // 为图的邻接表分配空间
        ids.resize(n, 0); // 初始化DFS次序为0
        lows.resize(n, 0); // 初始化最小DFS次序为0

        // 构建邻接表
        for (auto& connection : connections) {
            int u = connection[0];
            int v = connection[1];
            graph[u].push_back(v); // 添加边(u, v)
            graph[v].push_back(u); // 添加边(v, u)，因为是无向图
        }

        // 使用 Tarjan's 算法找到关键连接
        for (int i = 0; i < n; ++i) {
            if (ids[i] == 0) { // 如果当前节点还没有被访问过，则进行DFS
                dfs(i, -1); // 从当前节点开始进行DFS
            }
        }

        return result; // 返回关键连接的结果
    }
};

