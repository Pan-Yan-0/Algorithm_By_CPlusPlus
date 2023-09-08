//
// Created by 。 on 2023/9/6.
//

#include "lengthOfLIS.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int process(vector<int> &nums, int index, int length, int lastNum) {
        if (index == nums.size()) {
            return length;
        }
        int num1, num2;
        if (nums[index] <= lastNum) {
            num1 = process(nums, index + 1, length, lastNum);
        } else {
            num1 = process(nums, index + 1, length + 1, nums[index]);
        }
        num2 = process(nums, index + 1, length, lastNum);
        return max(num1, num2);
    }

    int DP(vector<int> &nums) {
        int n = nums.size();
        if (n <= 0) {
            return -1;
        }
        vector<int> dp(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] > nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }

    int greedy(vector<int> &nums) {
        vector<int> tails;
        tails.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (tails.back() > nums[i]) {
                int left = 0, right = tails.size();
                while (left < right) {
                    int mid = (left + right) / 2;
                    if (tails[mid] >= nums[i]) right = mid;
                    else left = mid + 1;
                }
                tails[left] = nums[i];
            } else {
                tails.push_back(nums[i]);
            }
        }
        return tails.size();
    }

public:
    int lengthOfLIS(vector<int> &nums) {
        return greedy(nums);
        //return DP(nums);
        //   return process(nums, 0, 0, -100000);
    }
};

//int main() {
//    Solution s;
//    vector<int> arr;
//    arr.push_back(10);
//    arr.push_back(9);
//    arr.push_back(2);
//    arr.push_back(5);
//    arr.push_back(3);
//    arr.push_back(7);
//    arr.push_back(101);
//    arr.push_back(18);
//    cout << s.lengthOfLIS(arr);
//    return 0;
//}