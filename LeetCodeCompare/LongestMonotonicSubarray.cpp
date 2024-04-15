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
    int longestMonotonicSubarray(vector<int> nums) {
        if (nums.size() == 1) return 1;

        bool com = false;
        if (nums[1] > nums[0]) com = true;
        int count = nums[1] == nums[0]?1:2;
        int ans = count;
        for (int i = 2; i < nums.size(); ++i) {
            if (com) {
                if (nums[i] > nums[i-1])count++;
                else{
                    com = false;
                    ans = max(ans,count);
                    count = 2;
                    if (nums[i] == nums[i-1])count--;
                }
            } else{
                if (nums[i]<nums[i-1])count++;
                else{
                    com = true;
                    ans = max(ans,count);
                    count = 2;
                    if (nums[i] == nums[i-1])count--;
                }
            }
        }
        ans = max(ans,count);
        return ans;
    }
};
//
//int main() {
//    Solution solution;
//    cout << solution.longestMonotonicSubarray({3,3,3,3});
//    return 0;
//}