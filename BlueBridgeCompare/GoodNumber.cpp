//
// Created by 。 on 2024/4/20.
//
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>
#include <list>
#include <stack>
#include <climits>
#include <numeric>

using namespace std;

class Solution {
public:
    int goodNum(int num) {
        int ans = 0;
        string toString = to_string(num);
        int n = toString.size();
        function<int(int, int)> fastPow = [&](int n, int po) {
            int ret = 1;
            for (int i = 0; i < po; ++i) {
                ret *= n;
            }
            return ret;
        };
        for (int i = 0; i < n; ++i) {
            if ((n - i) % 2 == 0) {
                ans += (toString[i] - '0' + 2 - 1) / 2 * fastPow(5, n - i - 1);
            } else {
                ans += (toString[i] - '0' + 1) / 2 * fastPow(5, n - i - 1);
            }
        }
        return ans;
    }

    int violent(int n) {
        int ans = 0;
        function<bool(int)> judge = [&](int num) {
            string toString = to_string(num);
            int size = toString.size();
            for (int i = 0; i < size; ++i) {
                if ((size - i) % 2 == 1) {
                    if ((toString[i] - '0') % 2 != 1) {
                        return false;
                    }
                } else {
                    if ((toString[i] - '0') % 2 != 0) {
                        return false;
                    }
                }
            }
            return true;
        };
        for (int i = 0; i < n; ++i) {
            if (judge(i)) ans++;
        }
        return ans;
    }
};

//int main() {
//    int n;
//    Solution solution;
//    cin >> n;
//    cout << solution.violent(n);
//    return 0;
//}