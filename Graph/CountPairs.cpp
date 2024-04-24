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

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> mark(n, 0);
        vector<vector<int>> unorderedMap(n);
        for (int i = 0; i < edges.size(); ++i) {
            unorderedMap[edges[i][0]].push_back(edges[i][1]);
            unorderedMap[edges[i][1]].push_back(edges[i][0]);
        }
        function<int(int)> dfs = [&](int index) -> int {
            mark[index] = 1;
            int sum = 1;
            for (int i = 0; i < unorderedMap[index].size(); ++i) {
                if (mark[unorderedMap[index][i]]) continue;
                sum += dfs(unorderedMap[index][i]);
            }
            return sum;
        };
        typedef long long ll;
        ll ans = 0;
        for (int i = 0, total = 0; i < mark.size(); ++i) {
            if (mark[i])
                continue;
            int temp = dfs(i);
            ans += (ll)temp * total;
            total += temp;
        }
        return ans;
    }
};
