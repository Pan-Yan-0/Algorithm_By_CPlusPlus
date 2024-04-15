//
// Created by 。 on 2024/3/10.
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
class Solution {
public:
    long long maximumStrength(vector<int> nums, int k) {
        int n = nums.size();
        vector<long long> s(n + 1); // 前缀和
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + nums[i];
        }
        // dp
        vector<vector<long long>> f(k + 1, vector<long long>(n + 1));

        for (int i = 1; i <= k; i++) {
            f[i][i - 1] = LLONG_MIN;
            long long mx = LLONG_MIN;
            int w = (k - i + 1) * (i % 2 ? 1 : -1);
            // j 不能太小也不能太大，要给前面留 i-1 个数，后面留 k-i 个数
            for (int j = i; j <= n - k + i; j++) {
                mx = max(mx, f[i - 1][j - 1] - s[j - 1] * w);
                f[i][j] = max(f[i][j - 1], s[j] * w + mx);
            }
        }
        return f[k][n];
    }
};

class Solution2 {
public:
    long long maximumStrength(vector<int> nums, int k) {
        int n = nums.size();
        vector<long long> a(k + 1, (long long) INT_MIN * n), b(k + 1, (long long) INT_MIN * n);
        a[0] = 0;
        long long res = LLONG_MIN;
        for (int i = 0; i < n; ++i) {
            for (int j = min(k, i + 1); j > 0; --j) {
                if (j & 1) {
                    // a[j]=max(a[j]+nums[i]*(long long)(k-j+1),a[j-1]+nums[i]*(long long)(k-j+1));
                    a[j] = max(a[j], a[j - 1]) + nums[i] * (long long) (k - j + 1);
                } else {
                    // a[j]=max(a[j]-nums[i]*(long long)(k-j+1),a[j-1]-nums[i]*(long long)(k-j+1));
                    a[j] = max(a[j], a[j - 1]) - nums[i] * (long long) (k - j + 1);
                }
                if (j == k) {
                    res = max(res, a[k]);
                }

            }
        }


        return res;
    }
};

class Solution1 {
public:
    long long maximumStrength(vector<int> nums, int k) {
        int n = nums.size();
        vector<long long> preSum(n + 1), preSumSquare(n + 1);

        // 预处理前缀和与前缀和的平方
        for (int i = 1; i <= n; ++i) {
            preSum[i] = preSum[i - 1] + nums[i - 1];
            preSumSquare[i] = preSumSquare[i - 1] + nums[i - 1] * nums[i - 1];
        }

        // 动态规划数组，dp[i][j] 表示在处理到下标 i 时选取 j 个子数组的最大能量值
        vector<vector<long long>> dp(n + 1, vector<long long>(nums.begin(), nums.end()));
        dp[0][0] = 0;

        // 动态规划状态转移
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, k); ++j) {
                for (int start = i - 1 - j + 1; start >= 0; --start) {
                    long long energy = (preSum[i] - preSum[start]) * j;
                    if (j > 1) {
                        energy -= (preSum[i - 1] - preSum[start]) * (j - 1);
                        energy += (preSumSquare[i] - preSumSquare[start] -
                                   (preSum[i] - preSum[start]) * (preSum[i] - preSum[start])) / 2;
                    }
                    dp[i][j] = max(dp[i][j], dp[start][j - 1] + energy);
                }
            }
        }

        return dp[n][k];
    }
};

//int main() {
//    Solution solution;
//    cout << solution.maximumStrength({1, 2, 3, -1, 2}, 3) << endl;
//    return 0;
//}