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
    string str;

    int process(int index) {
        if (index > str.size()) return 0;
        if (index == str.size()) return 1;
        if (str[index] == '0') return 0;
        int sum = 0;

        if (index + 1 < str.size() && str[index] <= '2') {
            if (str[index] == '2') {
                if (str[index + 1] <= '6') {
                    sum += process(index + 2);
                }
            } else {
                sum += process(index + 2);
            }
        }


        sum += process(index + 1);
        return sum;
    }

    int dpProcess(string s) {
        vector<int> dp(s.size() + 2, 0);
        dp[s.size()] = 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == '0') continue;
            dp[i] = dp[i + 1];
            if (s[i] > '2' || (s[i] == '2' && s[i + 1] > '6')) {
                continue;
            } else {
                dp[i] += dp[i + 2];
            }
        }
        return dp[0];
    }

    int numDecodings(string s) {
        str = s;
        return dpProcess(s);
    }
};

//int main() {
//    Solution solution;
//    cout << solution.numDecodings("226");
//    return 0;
//}