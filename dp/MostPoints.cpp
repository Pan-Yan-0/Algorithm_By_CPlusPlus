//
// Created by 。 on 2024/2/15.
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
    vector<vector<int>> arr;

    void printOneGraph(vector<int> graph) {
        for (const auto &item: graph) {
            cout << item << " ";
        }
        cout << endl;
    }

    void printTwoGraph(vector<vector<long long >> graph) {
        for (int i = 0; i < graph.size(); ++i) {
            for (int j = 0; j < graph[i].size(); ++j) {
                cout << graph[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    long long process(int k, int n) {
        if (k == arr.size()) return 0;
        if (n != 0) {
            return process(k + 1, n - 1);
        }

        long long i1 = process(k + 1, n + arr[k][1]) + arr[k][0];
        long long i2 = process(k + 1, n);
        return max(i1, i2);
    }

    long long dpProcess2(vector<vector<int>> questions, int maxJump) {
        vector<long long> dp(maxJump + 3, 0);
        for (int i = 0; i < questions.size(); ++i) {
            dp[0] = max(dp[0], dp[1]);
            int add = 1;
            for (int j = 1; j < maxJump + 2; ++j) {
                dp[j] = dp[j + 1];
                if (add == 1 && j == questions[i][1] + 1) {
                    dp[j] = max(dp[j],questions[i][0]+dp[0]);
                    add = 0;
                }
            }
        }
        long long maxNum = 0;
        for (const auto &item: dp){
            maxNum = max(maxNum,item);
        }
        return maxNum;
    }

    long long dpProcess(vector<vector<int>> questions, int maxJump) {
        vector<vector<long long >> dp(maxJump + 3, vector<long long>(questions.size() + 1, 0));
        for (int j = 1; j < dp[0].size(); ++j) {
            dp[0][j] = max(dp[0][j - 1], dp[1][j - 1]);
            int add = 1;
            for (int i = 1; i < dp.size() - 1; ++i) {
                dp[i][j] = dp[i + 1][j - 1];
                if (add == 1 && i == questions[j - 1][1] + 1) {
                    dp[i][j] = max(dp[i][j], questions[j - 1][0] + dp[0][j]);
                    add = 0;
                }
            }
        }
        long long maxNum = 0;
        for (int i = 0; i < dp.size(); ++i) {
            maxNum = max(dp[i][dp[i].size() - 1], maxNum);
        }
        printTwoGraph(dp);
        return maxNum;
    }

    long long mostPoints(vector<vector<int>> &questions) {
        int maxJump = 0;
        for (int i = 0; i < questions.size(); ++i) {
            arr.emplace_back(questions[i]);
            maxJump = max(maxJump, questions[i][1]);
        }
        return dpProcess2(questions, maxJump);
        return process(0, 0);
    }
};

//int main() {
//    Solution solution;
//    vector<vector<int>> arr = {{3, 2},
//                               {4, 3},
//                               {4, 4},
//                               {2, 5}};
//    cout << solution.mostPoints(arr);
//    return 0;
//}