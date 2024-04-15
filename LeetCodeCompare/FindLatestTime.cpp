//
// Created by 。 on 2024/4/14.
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

using namespace std;

class Solution {
public:
    string findLatestTime(string s) {
        if (s[0] == '?') {
            if (s[1] != '?') {
                if (s[1] >= '2') s[0] = '0';
                else s[0] = '1';
            } else {
                s[0] = '1';
            }
        }
        if (s[1] == '?') {
            if (s[0] == '0') {
                s[1] = '9';
            } else if (s[0] == '1') {
                s[1] = '1';
            }
        }
        if (s[3] == '?') {
            s[3] = '5';
        }
        if (s[4] == '?') {
            s[4] = '9';
        }
        return s;

    }
};

//int main() {
//    Solution s;
//    cout << s.findLatestTime("?1:?6");
//    return 0;
//}