//
// Created by 。 on 2024/4/18.
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

using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int> changed) {
        if (changed.size() % 2 == 1)return {};
        sort(changed.begin(), changed.end());
        vector<int> mark(changed.size(), 1);
        int l = 0, r = 1;
        vector<int> ans;
        while (r < changed.size()) {
            if (mark[l] == 0) {
                l++;
                continue;
            }
            if (l >= r) {
                r++;
                continue;
            }
            if (mark[r] == 0) {
                r++;
                continue;
            }
            if (changed[r] != changed[l] * 2) {
                r++;
            } else {
                ans.push_back(changed[l]);
                mark[l] -= 1;
                mark[r] -= 1;
                l++;
                r++;
            }
        }
        if (ans.size() != changed.size() / 2) {
            return {};
        }
        return ans;
    }
};

//int main() {
//    Solution solution;
//    vector<int> arr = solution.findOriginalArray({10, 6, 18, 3, 9, 5, 6, 3});
//    return 0;
//}
