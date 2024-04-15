//
// Created by 。 on 2024/2/21.
//
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> cost;
    vector<int> day;
    vector<int> add = {1, 7, 30};

    int process(int index) {
        if (index > day.size()) return 0;

        int minNum = INT32_MAX;
        for (int i = 0; i < 3; ++i) {
            int lastDay = day[index] + add[i] - 1;
            for (int j = index + 1; j < day.size(); ++j) {
                if (lastDay < day[j]) {
                    lastDay = j;
                    break;
                }
            }
            int temp = process(lastDay) + cost[i];
            minNum = min(minNum, temp);
        }
        cout << minNum << endl;
        return minNum;

    }

    int dpProcess(vector<int> days, vector<int> costs) {
        vector<int> dp(days[days.size() - 1] + 30, 100000000);
        for (int i = days.size() - 1; i >= 0; --i) {
            for (int j = 0; j < add.size(); ++j) {
                int indexDay = days[i] + add[j] - 1;
                int index;
                bool exchange = false;
                for (int k = i + 1; k < days.size(); ++k) {
                    if (days[k] > indexDay) {
                        exchange = true;
                        index = k;
                        break;
                    }
                }
                if (!exchange) {
                    dp[i] = min(dp[i],costs[j]);
                    continue;
                }
                dp[i] = min(dp[i], dp[index] + costs[j]);
            }
        }
        return dp[0];
    }

    int mincostTickets(vector<int> days, vector<int> costs) {
        day = days;
        cost = costs;
        return dpProcess(days, costs);
    }
};

//int main() {
//    Solution solution;
//    cout << solution.mincostTickets({1, 4, 6, 7, 8, 20}, {2, 7, 15});
//    return 0;
//}