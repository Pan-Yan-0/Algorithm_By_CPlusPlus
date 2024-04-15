//
// Created by 。 on 2024/4/14.
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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int ans = 0;
        vector<int> mark(isConnected.size(),0);
        for (int i = 0; i < isConnected.size(); ++i) {
            if (mark[i]){
                continue;
            }
            queue<int> qq;
            qq.push(i);
            ans++;
            while (!qq.empty()){
                int front = qq.front();

                qq.pop();
                if (mark[front]) continue;
                mark[front] = 1;
                for (int j = 0; j < isConnected[front].size(); ++j) {
                    if (isConnected[front][j]){
                        qq.push(j);
                    }
                }
            }
        }
        return ans;
    }
};
