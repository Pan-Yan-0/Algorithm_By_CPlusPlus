//
// Created by 。 on 2024/2/5.
//
#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) {
            int minn = INT32_MAX;
            for (int j = 1; j * j <= i; ++j) {
                minn = min(minn, dp[i - j * j]);
            }
            dp[i] = minn+1;
        }
        return dp[n];
    }
};
//
//int main() {
//    Solution solution;
//    cout << solution.numSquares(13);
//    return 0;
//}
