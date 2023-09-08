//
// Created by 。 on 2023/9/6.
//

#include "ASCALLMin.h"
#include<iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void print(vector<vector<int>> dp){
        int length1 = dp.size();
        int length2 = dp[0].size();
        for (int i = 0; i < length1 + 1; ++i) {
            for (int j = 0; j < length2 + 1; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        int length1 = s1.size();
        int length2 = s2.size();
        vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
        for (int i = 1; i < length1 + 1; ++i) {
            dp[i][0] = dp[i - 1][0] + s1[i - 1];
        }
        for (int i = 1; i < length2 + 1; ++i) {
            dp[0][i] = dp[0][i - 1] + s2[i - 1];
        }
        for (int i = 1; i < length1 + 1; ++i) {
            for (int j = 1; j < length2 + 1; ++j) {
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    int num1 = s2[j - 1] + dp[i][j - 1];
                    int num2 =  s1[i - 1] + dp[i - 1][j];
                    dp[i][j] = min(num1,num2);
                }
            }
        }
        for (int i = 0; i < length1 + 1; ++i) {
            for (int j = 0; j < length2 + 1; ++j) {
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
        return dp[length1 - 1][length2 - 1];
    }
};

//int main() {
//    Solution s;
//    cout << s.minimumDeleteSum("caabcccaccccca", "cacbaaac") << endl;
//    cout << 'e' + 0 << endl;
//    cout << 't' + 'r' << endl;
//    return 0;
//}
