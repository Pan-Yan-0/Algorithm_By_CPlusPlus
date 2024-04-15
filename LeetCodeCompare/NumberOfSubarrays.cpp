//
// Created by 。 on 2024/4/13.
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
    long long numberOfSubarrays(vector<int> nums) {
        long long ans = 0;
        int addArr[100000] = {0};
        addArr[1] = 1;
        for (int i = 2; i < 100000; ++i) {
            addArr[i] = addArr[i - 1] + i;
        }
        stack<pair<int, int>> ff;
        ff.push({nums[0], 1});
        for (int i = 1; i < nums.size(); ++i) {
            while (!ff.empty() && nums[i] > ff.top().first) {
                ans += addArr[ff.top().second];
                ff.pop();
            }
            if (!ff.empty()) {
                if (ff.top().first == nums[i]) {
                    ff.top().second++;
                } else {
                    ff.push({nums[i], 1});
                }
            } else {
                ff.push({nums[i], 1});
            }
        }
        while (!ff.empty()) {
            ans += addArr[ff.top().second];
            ff.pop();
        }

        return ans;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.numberOfSubarrays({1, 4, 3, 3, 2});
//    return 0;
//}