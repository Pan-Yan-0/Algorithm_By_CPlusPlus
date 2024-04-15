//
// Created by 。 on 2024/3/10.
//
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <cstdio>
#include <queue>
#include <climits>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long maximumHappinessSum(vector<int> happiness, int k) {
        sort(happiness.begin(), happiness.end());
        vector<int> dis(happiness.size() + 1, 0);
        for (int i = 1; i < happiness.size(); ++i) {
            dis[i] = happiness[i] - happiness[i - 1];
        }
        long long ans = 0;
        for (int i = 0, j = happiness.size() - 1; i < k && j >= 0; ++i, j--) {
            ans += happiness[j] - i > 0 ? happiness[j] - i : 0;
        }
        return ans;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.maximumHappinessSum({1, 2, 3}, 2);
//    return 0;
//}