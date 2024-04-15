//
// Created by 。 on 2024/2/9.
//
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    int account = 0;
    vector<int> arrs;
    vector<int> dp;
    vector<int> mark;

    int process(int target) {
        if (target < 0)return 0;
        if (target == 0) {
            return 1;
        }
        int account = 0;
        for (int i = 0; i < arrs.size(); ++i) {

            account += process(target - arrs[i]);
        }
        return account;
    }

    /*理论可解，但是由于某个值过大，导致dp表存不下*/
    int dpProcess(vector<int> nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (i - nums[j] < 0) break;
                dp[i] += dp[i - nums[j]];

            }
        }
        return dp[target];
    }

    int combinationSum4(vector<int> nums, int target) {
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 0; --i) {
            arrs.emplace_back(nums[i]);
        }
        dp = vector<int>(target + 1, 0);
        dp[0] = 1;
        mark = vector<int>(target + 1, 0);
        dpProcess2(target);
        return dp[target];
//        int i1 = process(target);
//        return i1;
        // return dpProcess(nums, target);
    }


    void dpProcess2(int nums) {
        for (int i = arrs.size() - 1; i >= 0; --i) {
            if (nums - arrs[i] < 0) continue;
            if (!mark[nums - arrs[i]]) {
                dpProcess2(nums - arrs[i]);

            }
            dp[nums] += dp[nums - arrs[i]];
        }
        mark[nums] = 1;

    }
};

//int main() {
//    Solution solution;
//
//    cout << solution.combinationSum4(
//            {1, 2, 3}, 4);
//    return 0;
//}