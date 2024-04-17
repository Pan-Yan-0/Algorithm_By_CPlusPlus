//
// Created by 。 on 2024/4/16.
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
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> &redEdges, vector<vector<int>> &blueEdges) {
        vector<vector<int>> redMatrix(n, vector<int>(n, 0)), blueMatrix(n, vector<int>(n, 0));
        for (int i = 0; i < redEdges.size(); ++i) {
            int x = redEdges[i][0], y = redEdges[i][1];
            redMatrix[x][y] = 1;
        }
        for (int i = 0; i < blueEdges.size(); ++i) {
            int x = blueEdges[i][0], y = blueEdges[i][1];
            blueMatrix[x][y] = 1;
        }
        vector<int> ans(n, -1);
        ans[0] = 0;
        for (int i = 1; i < n; ++i) {
            queue<vector<int>> qq;
            vector<bool> blue(n, 0), red(n, 0);
            int minCount = n + 1;
            bool find = false;
            for (int j = 0; j < redMatrix[0].size(); ++j) {
                if (redMatrix[0][j]) {
                    if (j == i) {
                        ans[i] = 1;
                        find = true;
                        break;
                    }
                    qq.push({j, 0, 1});
                }
            }
            for (int j = 0; j < blueMatrix[0].size(); ++j) {
                if (blueMatrix[0][j]) {
                    if (j == i) {
                        ans[i] = 1;
                        find = true;
                        break;
                    }
                    qq.push({j, 1, 1});
                }
            }
            if (find) continue;
            while (!qq.empty()) {
                vector<int> temp = qq.front();
                int time = temp[2], index = temp[0], color = temp[1];
                qq.pop();
                if (color == 1) {
                    if (red[index]) continue;
                    red[index] = true;
                    for (int j = 0; j < redMatrix[index].size(); ++j) {
                        if (redMatrix[index][j]) {
                            if (j == i) minCount = min(time + 1, minCount);
                            qq.push({j, 0, time + 1});
                        }
                    }
                } else {
                    if (blue[index]) continue;
                    blue[index] = true;
                    for (int j = 0; j < blueMatrix[index].size(); ++j) {
                        if (blueMatrix[index][j]) {
                            if (j == i) minCount = min(time + 1, minCount);
                            qq.push({j, 1, time + 1});
                        }
                    }
                }
            }
            ans[i] = (minCount == n + 1 ? ans[i] : minCount);

        }
        return ans;

    }
};
