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
//map存储层级树结构
//bfs
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if (n == 1) return 0;
        unordered_map<int,vector<int>> unorderedMap;
        for (int i = 0; i < manager.size(); ++i) {
            if (manager[i] == -1)continue;
            unorderedMap[manager[i]].push_back(i);
        }
        queue<pair<int,int>> qq;
        qq.push({headID,0});
        int ans = 0;
        while (!qq.empty()){
            auto [front,time] = qq.front();
            qq.pop();
            if (informTime[front] == 0) ans = max(time,ans);
            for (int i = 0; i < unorderedMap[front].size(); ++i) {
                qq.push({unorderedMap[front][i],time + informTime[front]});
            }
        }
        return ans;
    }
};