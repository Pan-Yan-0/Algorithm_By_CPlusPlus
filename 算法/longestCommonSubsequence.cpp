//
// Created by 。 on 2023/9/18.
//

#include "longestCommonSubsequence.h"
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class Solution {
private:
    int process(string str1, string str2) {
        int length1 = str1.size();
        int length2 = str2.size();
        vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));
        for (int i = length1 - 1; i >= 0; --i) {
            bool addOne = false;
            dp[i][length2 - 1] = dp[i + 1][length2 - 1];
            for (int j = length2 - 2; j >= 0; --j) {
                dp[i][j] = dp[i][j + 1];
                if (str1[i] == str2[j] && !addOne) {
                    dp[i][j]++;
                    addOne = true;
                }
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[0][0];
    }

    int DP(string str1, string str2) {
        int length1 = str1.size();
        int length2 = str2.size();
        vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));
        for (int i = 1; i <= length1; ++i) {
            for (int j = 1; j <= length2; ++j) {
                if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[length1][length2];
    }

    int DPMax(string str1, string str2) {
        int length1 = str1.size();
        int length2 = str2.size();
        vector<int> dp(length2 + 1, 0);
        int dpij = 0;
        for (int i = 1; i <= length1; ++i) {
            for (int j = 1; j <= length2; ++j) {
                int temp = dp[j];
                if (str1[i - 1] == str2[j - 1]) dp[j] = dpij + 1;
                else dp[j] = max(dp[j-1],dp[j]);
                dpij = temp;
            }
        }
        return dp[length2];
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        return DPMax(text1, text2);
    }
};

//int main() {
//    Solution s;
//    string str1 = "abcde";
//    string str2 = "ace";
//    cout << s.longestCommonSubsequence(str1, str2);
//    return 0;
//}