//
// Created by 。 on 2024/3/8.
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
    const static int modNum = 1e9 + 7;

    int minimumPossibleSum(int n, int target) {
        long long k = target / 2;
        long long ans = 0;
        if (n > k) {
            ans = ((k + k * k) / 2) % modNum;
            long long temp = ((long long) (target + n - k - 1 + target) * (n - k) / 2) % modNum;
            ans = (ans + temp) % modNum;
        }else {
            ans = ((long long )(n * n + n) / 2) % modNum;
        }
        return (int)ans;

    }
};

//int main() {
//    Solution solution;
//    cout << solution.minimumPossibleSum(1e9, 1e9);
//    return 0;
//}