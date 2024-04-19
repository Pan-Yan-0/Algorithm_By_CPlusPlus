//
// Created by 。 on 2024/4/17.
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
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph) {
        int n = graph.size() - 1;
        vector<vector<int>> ans;
        function<void(vector<int>,int )> dfs = [&](vector<int> arr,int index) {
            arr.push_back(index);
            if (index == n) {
                ans.push_back(arr);
                return ;
            }
            for (int i = 0; i < graph[index].size(); ++i) {
                dfs(vector<int>(arr),graph[index][i]);
            }
        };
        dfs(vector<int>(),0);
        return ans;
    }
};
