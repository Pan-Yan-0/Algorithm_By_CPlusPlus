//
// Created by 。 on 2024/4/15.
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

//先终端节点，再安全节点
// bfs
    // 本题来说，一开始的思路是正确的，就是不太熟练，导致一直卡住
    //  总体来说就是对图论使用的不熟悉，并没有对一、二维数组的数论知识的地步
    // 需要继续练习，特别是bfs与dfs还有拓扑排序
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        vector<vector<int>> matrix(graph.size());
        vector<int> inDeg(graph.size(), 0);
        // 反向图，方便寻找可以到达这个安全点的点，并且在之后进队，判断是否可以成为这个点是否可以成为安全点，安全点是不增加出队的
        // 故在创建出队数组，统计各个点的出度是多少，
        for (int i = 0; i < graph.size(); ++i) {
            inDeg[i] = graph[i].size();
            for (int j = 0; j < graph[i].size(); ++j) {
                matrix[graph[i][j]].push_back(i);
            }
        }
        //
        queue<int> qq;
        for (int i = 0; i < inDeg.size(); ++i) {
            if (inDeg[i] == 0) qq.push(i);
        }
        while (!qq.empty()) {
            int front = qq.front();
            for (int i = 0; i < matrix[front].size(); ++i) {
                int temp =matrix[front][i];
                inDeg[temp]--;
                if (inDeg[temp]==0) qq.push(temp);
            }
        }
        vector<int> ans;
        for (int i = 0; i < inDeg.size(); ++i) {
            if (inDeg[i]==0) ans.push_back(i);
        }
        return ans;
    }
};

class Solution1 {
public:
    vector<vector<int>> matrix;

    int dfs(int index) {
        if (matrix[index].size() == 0) {
            return index;
        }
        bool same = true;
        for (int i = 0; i < matrix[index].size(); ++i) {
            if (matrix[index][i] == index) continue;

        }
    }

    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        matrix = graph;
        for (int i = 0; i < graph.size(); ++i) {
            dfs(i);
        }
    }
};