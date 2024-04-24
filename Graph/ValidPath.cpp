//
// Created by 。 on 2024/4/22.
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
#include <numeric>

using namespace std;

class Solution1 {
public:
    bool validPath(int n, vector<vector<int>> &edges, int source,
                   int destination) {
        unordered_map<int, vector<int>> matrix;
        for (int i = 0; i < edges.size(); ++i) {
            matrix[edges[i][0]].push_back(edges[i][1]);
            matrix[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> mark(n, 0);
        bool find = false;
        function<void(int)> dfs = [&](int index) {
            if (find) return;
            if (index == destination) {
                find = true;
                return;
            }
            if (mark[index]) return;
            mark[index] = true;
            for (int i = 0; i < matrix[index].size(); ++i) {
                dfs(matrix[index][0]);
            }
            mark[index] = false;
        };
        dfs(source);
        return find;
    }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
        vector<int> p(n, 0);
        iota(p.begin(), p.end(), 0);
        function<int(int)> QuickFind = [&](int root) -> int {
            return p[root];
        };
        function<void(int, int)> Union = [&](int root1, int root2) -> void {
            int rootX = p[root1];
            int rootY = p[root2];
            if (rootX != rootY) {
                for (int i = 0; i < p.size(); ++i) {
                    if (p[i] == rootY) p[i] = rootX;
                }
            }
        };
        function<bool(int, int)> connected = [&](int root1, int root2) -> bool {
            return p[root1]==p[root2];
        };
        for (int i = 0; i < edges.size(); ++i) {
            Union(edges[i][0],edges[i][1]);
        }
        return connected(source,destination);
    }
};