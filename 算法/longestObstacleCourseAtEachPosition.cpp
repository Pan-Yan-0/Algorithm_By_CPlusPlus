//
// Created by 。 on 2023/9/15.
//

#include "longestObstacleCourseAtEachPosition.h"
#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
    //1,1,2,2,2,3,4,5,4,6,6,2,3,7,7,8,5
private:
    int findNum(vector<int> nums, int number, int index) {
        for (int i = index - 1; i >= 0; --i) {
            if (nums[i] <= number) {
                return i;
            }
        }
        return -1;
    }

    vector<int> DP(vector<int> nums) {
        int length = nums.size();
        vector<int> dp(length, 1);
        for (int i = 1; i < length; ++i) {
            int index = findNum(nums, nums[i], i);
            if (index == -1) {
            } else {
                dp[i] = dp[index] + 1;
            }
        }
        return dp;
    }

    vector<int> DP1(vector<int> nums) {
        int length = nums.size();
        vector<int> dp(length, 1);
        for (int i = 1; i < length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] >= nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp;
    }

public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles) {
        return DP1(obstacles);
    }
};

int main() {

    Solution s;
    vector<int> nums;
    //201,19,363,292,123,211,333,387,296,500,401,42,176,476,473,498
    nums.push_back(201);
    nums.push_back(19);
    nums.push_back(363);
    nums.push_back(292);
    nums.push_back(123);
    nums.push_back(211);
    nums.push_back(333);
    nums.push_back(387);
    nums.push_back(296);
    nums.push_back(500);
    nums.push_back(401);
    nums.push_back(42);
    nums.push_back(176);
    nums.push_back(476);
    nums.push_back(473);
    nums.push_back(498);
    for (const auto &item: s.longestObstacleCourseAtEachPosition(nums)) {
        cout << item << " ";
    }
    cout << endl;

    return 0;
}