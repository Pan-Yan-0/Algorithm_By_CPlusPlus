//
// Created by 。 on 2024/2/18.
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
    int low, high, zero, one;

    int process(int sizeStr) {
        if (sizeStr > high) return 0;
        int count = 0;
        if (sizeStr >= low) count++;
        count += process(sizeStr + zero);
        count += process(sizeStr + one);
        return count;
    }

    int dpProcess(int low, int high, int zero, int one) {
        int sizeArr = high + 1;
        sizeArr += zero > one ? zero : one;
        vector<int> dp(sizeArr, 0);
        dp[high] = 1;
        for (int i = high - 1; i >= 0; --i) {
            long temp = dp[i + one] + dp[i + zero];
            dp[i] = temp % 1000000007;

            if (i >= low && i <= high) dp[i]++;

        }
        return dp[0];
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        this->low = low;
        this->high = high;
        this->zero = zero;
        this->one = one;
        return dpProcess(low, high, zero, one) % 1000000007;
    }
};
//
//int main() {
//    Solution solution;
//    cout << solution.countGoodStrings(3, 3, 1, 1);
//    return 0;
//}