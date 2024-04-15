//
// Created by 。 on 2024/2/17.
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
    vector<int> arr;
    int minReturn = INT32_MAX;
    int record = -1;

    void process(int leftover, int k) {
        if (leftover < 0)return;
        if (leftover == 0) {
            minReturn = min(k, minReturn);
            record = 0;
        }
        for (int i = 0; i < arr.size(); ++i) {
            process(leftover - arr[i], k + 1);
        }
    }

    int bfs(vector<int> coins, int amount) {
        if (amount == 0) return 0;

        vector<int> last = {amount};
        vector<int> next;
        vector<int> mark(amount, 0);
        next.erase(next.begin(), next.end());
        int count = 0;
        int maxCircle = amount / coins[0] + 1;
        while (true) {
            if (count == maxCircle) return -1;
            for (int i = 0; i < last.size(); ++i) {
                for (int j = 0; j < coins.size(); ++j) {
                    int args = last[i] - coins[j];
                    if (args < 0)continue;
                    if (mark[args] == 0) {
                        next.emplace_back(args);
                        if (args == 0) {
                            return count + 1;
                        }
                        mark[args] = 1;
                    }
                }
            }
            last.clear();
            for (int i = 0; i < next.size(); ++i) {
                last.emplace_back(next[i]);
            }
            count++;
            next.clear();
            if (count == maxCircle) return -1;
        }

    }

    int coinChange(vector<int> coins, int amount) {
        if (amount == 0) return 0;
        sort(coins.begin(), coins.end());
        return bfs(coins, amount);
        arr = coins;
        process(amount, 0);

        return record == -1 ? -1 : minReturn;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.coinChange({1, 2, 5}, 100);
//    return 0;
//}