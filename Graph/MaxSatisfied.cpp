//
// Created by 。 on 2024/4/23.
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
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes) {
        vector<int> vals(customers.size(), 0);
        int ans = 0;
        int ansTemp = 0;
        for (int i = 0; i < customers.size(); ++i) {
            if (!grumpy[i]) ans += customers[i];
            vals[i] = grumpy[i] * customers[i];
        }
        if (vals.size() <= minutes) {
            for (int i = 0; i < vals.size(); ++i) {
                ansTemp += vals[i];
            }

        } else {
            for (int i = 0; i < minutes; ++i) {
                ansTemp+=vals[i];
            }
            int last = ansTemp;
            for (int i = minutes; i < vals.size(); ++i) {
                last = last + vals[i-minutes]+vals[i];
                ansTemp = max(last,ansTemp);
            }
        }
        return ansTemp + ans;


    }
};
