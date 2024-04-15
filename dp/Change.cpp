//
// Created by 。 on 2024/2/7.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> arrs;
    vector<vector<int>> dp2;

    int process(int nnum, int k) {

        if (nnum < 0) return 0;
        if (nnum == 0) {
            return 1;
        }
        int mount = 0;
        for (int i = k; i < arrs.size(); ++i) {
            cout << nnum << " - " << arrs[i] << " k = " << i << endl;
            mount += process(nnum - arrs[i], i);
        }
        return mount;

    }

    int change(int amount, vector<int> coins) {
        for (int i = coins.size() - 1; i >= 0; --i) {
            arrs.emplace_back(coins[i]);
        }
        sort(coins.begin(), coins.end());
        return 0;
    }

    void printOneGraph(vector<int> graph) {
        for (const auto &item: graph) {
            cout << item << " ";
        }
        cout << endl;
    }

    void printTwoGraph(vector<vector<int>> graph) {
        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    int dpProcess(int amount, vector<int> coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size(), 0));
        for (int i = 0; i < coins.size(); ++i) {
            dp[0][i] = 1;
        }
        for (int i = 1; i <= amount; ++i) {
            for (int j = coins.size() - 1; j >= 0; --j) {
                dp[i][j] = dp[i][j + 1];
                if (i - coins[j] < 0)continue;
                int sum = 0;
                for (int k = j; k < coins.size(); ++k) {
                    sum += dp[i - coins[k]][k];
                }
                dp[i][j] = max(dp[i][j], sum);
            }
        }
        printTwoGraph(dp);
        return dp[amount][0];
    }


    int dpProcess1(int amount, vector<int> coins) {
        vector<vector<int>> dp(amount + 1, vector<int>(coins.size() + 1, 0));
        for (int i = 0; i < coins.size() + 1; ++i) {
            dp[0][i] = 1;
        }
        for (int j = coins.size() - 1; j >= 0; --j) {
            for (int i = coins[j]; i <= amount; i += coins[j]) {
                dp[i][j] = dp[i][j + 1];
                if (i - coins[j] < 0)continue;
                int sum = 0;
                for (int k = j; k < coins.size(); ++k) {
                    sum += dp[i - coins[k]][k];
                }
                dp[i][j] = max(dp[i][j], sum);
            }
        }
        printTwoGraph(dp);
        return dp[amount][0];
    }
};

class Solution1 {
public:
    vector<int> arrs;

    int process(int nnum, int k) {

        if (nnum < 0) return 0;
        if (nnum == 0) {
            return 1;
        }
        int mount = 0;
        for (int i = k; i < arrs.size(); ++i) {
            cout << nnum << " - " << arrs[i] << " k = " << i << endl;
            mount += process(nnum - arrs[i], i);
        }
        return mount;

    }

    int change(int amount, vector<int> coins) {
        for (int i = coins.size() - 1; i >= 0; --i) {
            arrs.emplace_back(coins[i]);
        }
        int i1 = process(amount, 0);
        return i1;
    }

};

class Solution2 {
public:
    vector<vector<int>> dp;
    vector<int> arr;
    vector<vector<int>> mark;

    void process(int num, int k) {
        if (num < 0) return;
        for (int i = k; i < arr.size(); ++i) {
            if (num-arr[i]<0)continue;
            if (mark[num - arr[i]][i]) {
                dp[num][k] += dp[num - arr[i]][i];
            } else {
                process(num - arr[i], i);
                dp[num][k] += dp[num - arr[i]][i];
            }
        }
        mark[num][k] = 1;
    }

    int change(int amount, vector<int> coins) {
        dp = vector<vector<int>>(amount + 1, vector<int>(coins.size() + 1, 0));
        mark = vector<vector<int>>(amount + 1, vector<int>(coins.size() + 1, 0));
        for (int i = 0; i < coins.size() + 1; ++i) {
            dp[0][i] = 1;
        }
        sort(coins.begin(), coins.end());
        for (int i = coins.size() - 1; i >= 0; --i) {
            arr.emplace_back(coins[i]);
        }
        for (int i = coins.size() - 1; i >= 0; --i) {
            process(amount, i);
            dp[amount][i] = max(dp[amount][i], dp[amount][i + 1]);

        }
        return dp[amount][0];
    }
};

//int main() {
//    Solution2 solution;
//
//    cout << solution.change(5, {1, 2, 5});
//    return 0;
//}