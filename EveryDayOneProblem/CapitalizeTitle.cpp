//
// Created by 。 on 2024/3/11.
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
    string capitalizeTitle(string title) {
        int left = 0;
        for (int i = 0; i < title.size(); ++i) {
            if (title[i] == ' ') {
                if (i - left > 2) {
                    title[left] -= 'z' - 'Z';
                }
                left = i + 1;
                continue;
            }
            if (title[i] <= 'Z') {
                title[i] += 'z' - 'Z';
            }
        }
        if (title.size() - left > 2) {
            title[left] -= 'z' - 'Z';
        }
        return title;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.capitalizeTitle("First leTTeR of EACH Word");
//    return 0;
//}