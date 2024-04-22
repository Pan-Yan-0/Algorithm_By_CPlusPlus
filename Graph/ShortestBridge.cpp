//
// Created by 。 on 2024/4/18.
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
    int x[4] = {0, 0, 1, -1};
    int y[4] = {1, -1, 0, 0};
public:
    int shortestBridge(vector<vector<int>> &grid) {
        int n = grid.size();
        queue<pair<int, int>> qq;
        for (int i = 0; i < n; ++i) {
            bool find = false;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    find = true;
                    qq.push({i, j});
                    break;
                }
            }
            if (find)break;
        }
        while (!qq.empty()) {
            auto [xI, yI] = qq.front();

        }
    }
};
