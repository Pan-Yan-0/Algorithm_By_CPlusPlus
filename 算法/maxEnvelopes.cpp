//
// Created by 。 on 2023/9/14.
//

#include "maxEnvelopes.h"
#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
private:
    // 暴力递归
    int process(vector<vector<int>> envelpes, int index, map<int, int> dp) {
        if (index == envelpes.size()) {
            return 0;
        }
        int num1 = process(envelpes, index + 1, map<int, int>(dp));
        int addNum = 0;
        if (dp.empty()) {
            dp.insert({envelpes[index][0], envelpes[index][1]});
            addNum = 1;
        } else {
            int mark = 0;
            for (const auto &item: dp) {
                if (!mark) {
                    if (item.first > envelpes[index][0] && item.second > envelpes[index][1]) {
                        mark = 1;
                    }
                } else {
                    if (item.first < envelpes[index][0] && item.second < envelpes[index][1]) {
                        mark = 0;
                        dp.insert({envelpes[index][0], envelpes[index][1]});
                        addNum = 1;
                        break;
                    } else {
                        mark = 0;
                        break;
                    }
                }
            }
            mark = 0;
            for (const auto &item: dp) {
                if (!mark) {
                    if (item.first < envelpes[index][0] && item.second < envelpes[index][1]) {
                        mark = 1;
                    }
                } else {
                    if (item.first > envelpes[index][0] && item.second > envelpes[index][1]) {
                        mark = 0;
                        dp.insert({envelpes[index][0], envelpes[index][1]});
                        addNum = 1;
                        break;
                    } else {
                        mark = 0;
                        break;
                    }
                }
            }
        }
        int num2 = process(envelpes, index + 1, map<int, int>(dp)) + addNum;
        cout << num1 << "        " << num2 << endl;
        return max(num1, num2);
    }

    void print(vector<vector<int>> arr) {
        unsigned long size1 = arr.size();
        unsigned long size2 = arr[0].size();
        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size2; ++j) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    int DP2(vector<vector<int>> envelopes) {
        if (envelopes.empty()) {
            return 0;
        }
        int n = envelopes.size();
        print(envelopes);
        cout<<"-------------------------------------------"<<endl;
        sort(envelopes.begin(), envelopes.end(), [](const auto &e1, const auto &e2) {
            return e1[0] < e2[0] || (e1[0] == e2[0] && e1[1] > e2[1]);
        });
        print(envelopes);
        vector<int> f = {envelopes[0][1]};
        for (int i = 1; i < n; ++i) {
            if (int num = envelopes[i][1]; num > f.back()) {
                f.push_back(num);
            } else {
                auto it = lower_bound(f.begin(), f.end(), num);
                *it = num;
            }
        }
        return f.size();
    }

    int DP(vector<vector<int>> envelopes) {
        int length = envelopes.size();
        print(envelopes);
        cout << "----------------------------" << endl;
        sort(envelopes.begin(), envelopes.end());
        print(envelopes);
        vector<int> dp(length, 1);
        dp[0] = 1;
        for (int i = 1; i < length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (envelopes[i][1] > envelopes[j][1] && envelopes[i][0] != envelopes[j][0]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

public:
    int maxEnvelopes(vector<vector<int>> &envelopes) {

        return DP2(envelopes);
    }
};

int main() {
    Solution s;
    vector<vector<int>> nums;
    //输入：envelopes = [[5,4],[6,4],[6,7],[2,3]]
    //[[4,5],[4,6],[6,7],[2,3],[1,1]]
    vector<int> num;
    num.push_back(4);
    num.push_back(5);
    nums.push_back(num);
    num.clear();
    num.push_back(4);
    num.push_back(6);
    nums.push_back(num);
    num.clear();
    num.push_back(6);
    num.push_back(7);
    nums.push_back(num);
    num.clear();
    num.push_back(2);
    num.push_back(3);
    nums.push_back(num);
    num.clear();
    num.push_back(1);
    num.push_back(1);
    nums.push_back(num);
    num.clear();

    cout << s.maxEnvelopes(nums);
    return 0;
}