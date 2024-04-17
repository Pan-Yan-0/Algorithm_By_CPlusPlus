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
    int minReorder(int n, vector<vector<int>> &connections) {
        unordered_map<int, bool> canGet;
        unordered_map<int, vector<int>> connect;
        unordered_map<int,vector<int>> canArrive;
        canGet[0] = true;

        queue<int> qq;
        qq.push(0);
        for (int i = 0; i < connections.size(); ++i) {
            int x = connections[i][0], y = connections[i][1];
            if (y == 0) {
                qq.push(x);
                canGet[x] = true;
            }
            canArrive[x].push_back(y);
            connect[x].push_back(y);
            connect[y].push_back(x);
        }
        int count = 0;
        while (!qq.empty()) {
            int front = qq.front();
            qq.pop();
            for (int i = 0; i < connect[front].size(); ++i) {
                int temp = connect[front][i];
                // 本处判断出现问题，应该是看这个节点是否可以到达这个canGet内的节点，而不是判断这个节点是否是canGet节点
                // 如何去判断是否是可以到达canGet节点
                bool can = false;
                for (int j = 0; j < canArrive[temp].size(); ++j) {
                    if (canGet[canArrive[temp][j]]){
                        canGet[temp] = true;
                        can = true;
                        qq.push(temp);
                    }
                }
                if (!can) {
                    canGet[temp] = true;
                    count++;
                    qq.push(temp);
                }
            }
        }
        return count;
    }
};