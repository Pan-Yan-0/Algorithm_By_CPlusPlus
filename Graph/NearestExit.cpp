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
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        int nX = maze.size();
        int nY = maze[0].size();
        queue<tuple<int,int,int>> qq;
        qq.push({entrance[0], entrance[1], 0});
        while (!qq.empty()) {
            auto [xI,yI,time] = qq.front();
            qq.pop();
            if (xI != entrance[0] || yI != entrance[1]) {
                if (xI == nX - 1 || yI == nY - 1 ||xI==0||yI==0)return time;
            }
            if (maze[xI][yI]=='+') continue;
            maze[xI][yI] = '+';
            for (int i = 0; i < 4; ++i) {
                if (xI + x[i] < 0 || xI + x[i] >= nX || yI + y[i] < 0 || yI + y[i] >= nY ||
                    maze[xI + x[i]][yI + y[i]] == '+')
                    continue;
                qq.push({xI + x[i], yI + y[i], time + 1});
            }
        }
        return -1;
    }
};
