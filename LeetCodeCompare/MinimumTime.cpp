//
// Created by 。 on 2024/4/13.
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

using namespace std;

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>> edges, vector<int> disappear) {
        unordered_map<int,vector<pair<int,int>>> graph;
        for (auto &item: edges){
            graph[item[0]].push_back({item[1],item[2]});
            graph[item[1]].push_back({item[0],item[2]});
        }

    }

};

//int main() {
//    Solution s;
//    s.minimumTime(3, {{}}, {});
//    return 0;
//}