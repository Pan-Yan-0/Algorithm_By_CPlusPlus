//
// Created by 。 on 2024/3/30.
//
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <cstdio>
#include <queue>
#include <climits>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#include <vector>
#include <limits>

using namespace std;

class Solution {
public:
    typedef long long ll;

    int minimumSubarrayLength(vector<int> nums, int k) {
        int minNum = 10e6;
        int n = nums.size() - 1;
        vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
        for (int i = n; i >= 0; --i) {
            dp[i][i] = nums[i];
            if (k <= dp[i][i]) return 1;
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                dp[i][j] = dp[i][j - 1] | nums[j];
                if (dp[i][j] >= k) {
                    minNum = min(minNum, j - i + 1);
                }
            }
        }
        if (minNum == 10e6) return -1;
        return minNum;

    }
};

//int main() {
//    Solution solution;
//    cout << solution.minimumSubarrayLength({1,2,3}, 2);
//
//    return 0;
//}