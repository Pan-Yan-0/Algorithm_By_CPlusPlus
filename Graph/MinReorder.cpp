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

class Solution1 {
public:
    int minReorder(int n, vector<vector<int>> &connections) {
        unordered_map<int, bool> canGet;
        unordered_map<int, vector<int>> connect;
        unordered_map<int, vector<int>> canArrive;
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
                    if (canGet[canArrive[temp][j]]) {
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

class Solution {
public:
    int minReorder(int n, vector<vector<int>> &connections) {
        unordered_map<int, vector<int>> canCome;
        unordered_map<int, vector<int>> getCome;
        unordered_map<int, bool> get;
        int ans = 0;
        for (int i = 0; i < connections.size(); ++i) {
            canCome[connections[i][1]].push_back(connections[i][0]);
            getCome[connections[i][0]].push_back(connections[i][1]);
            getCome[connections[i][1]].push_back(connections[i][0]);
        }
        queue<int> qq;
        qq.push(0);
        get[0] = true;
        while (!qq.empty()) {
            int front = qq.front();
            qq.pop();
            for (int i = 0; i < getCome[front].size(); ++i) {
                if (get[getCome[front][i]]) continue;
                bool findNum = false;
                for (int j = 0; j < canCome[front].size(); ++j) {
                    if (canCome[front][j] == getCome[front][i]){
                        findNum = true;
                        break;
                    }
                }
                if (!findNum) ans++;
                get[getCome[front][i]] = true;
                qq.push(getCome[front][i]);
            }
        }
        return ans;
    }
};