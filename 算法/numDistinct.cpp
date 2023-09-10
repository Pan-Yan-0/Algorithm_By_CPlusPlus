//
// Created by 。 on 2023/9/8.
//

#include "numDistinct.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    void print(vector<vector<int>> dp) {
        int length1 = dp.size();
        int length2 = dp[0].size();
        for (int i = 0; i < length1; ++i) {
            for (int j = 0; j < length2; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
    // 递归暴力算法
    int process(string ori, string str, string tar, int index) {
        if (str.size() == tar.size()) {
            if (str == tar) {
                return 1;
            } else {
                return 0;
            }
        }
        if (index == ori.size()) {
            return 0;
        }
        int num1 = process(ori, str, tar, index + 1);
        string newStr = string(str + ori[index]);
        int num2 = process(ori, newStr, tar, index + 1);
        return num1 + num2;
    }

    int dp(string s, string t) {
        int m = s.length(), n = t.length();
        if (m < n) {
            return 0;
        }
        vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1,0));
        for (int i = 0; i <= m; i++) {
            dp[i][n] = 1;
        }
        for (int i = m - 1; i >= 0; i--) {
            char sChar = s.at(i);
            for (int j = n - 1; j >= 0; j--) {
                char tChar = t.at(j);
                if (sChar == tChar) {
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
//    int dp(string s,string t){
//        int length1 = s.size();
//        int length2 = t.size();
//        vector<vector<int>> dp(length1, vector<int>(length2,0));
//        for (int i = 0; i < ; ++i) {
//
//        }
//    }
public:
    int numDistinct(string s, string t) {
        return dp(s, t);
//        string str;
//        return process(s, str, t, 0);
    }
};

//int main() {
//    Solution s;
//    cout << s.numDistinct("babgbag", "bag") << endl;
//    return 0;
//}