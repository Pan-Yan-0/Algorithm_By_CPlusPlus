//
// Created by 。 on 2024/4/7.
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
#include <limits>

using namespace std;

class Solution {
public:
    int distance(string s1, string s2) {
        for (int i = 0; i < s1.size(); ++i) {

        }
    }

    string getSmallestString(string s, int k) {
        if (k == 0) return s;
        string ans(s);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] + k - 26 >= 'a' || s[i] - k < 'a') {
                ans[i] = 'a';
                if ('a' - s[i] + 26 < s[i] - 'a') {
                    k -= 'a' - s[i] + 26;
                } else {
                    k -= s[i] - 'a';
                }
            } else {
                ans[i] = s[i] - k;
                k = 0;
            }
            if (k == 0) break;
        }
        return ans;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.getSmallestString("zbbz", 3);
//    return 0;
//}