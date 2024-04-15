//
// Created by 。 on 2024/3/4.
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

using namespace std;

class Solution {
public:
    int DoublePointSolution(vector<int> nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](auto a, auto b) {
            return a < b;
        });
        int total = 0;
        for (int i = nums.size() - 1; i >= 2; --i) {
            int j = 0, k = i - 1;
            while (j < k) {
                if (nums[i] < nums[j] + nums[k]) {
                    total += k - j;
                    k--;
                } else {
                    j++;
                }
            }

        }
        return total;
    }

    int DoublePointSolution2(vector<int> nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), [](auto a, auto b) {
            return a < b;
        });
        int total = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1, k = i + 2;
            while (j < k) {
                if (nums[i] + nums[j] <= nums[k] || k == n) {
                    if (nums[i] + nums[j] <= nums[k]) {
                        total += k - j;
                    }
                    j++;
                } else {
                    if (k < n) {
                        k++;
                    }
                }
            }
        }
        return total;
    }

    int triangleNumber(vector<int> nums) {
        int total = DoublePointSolution2(nums);
        return total;
    }

    int BSSolution(vector<int> &nums) const {
        sort(nums.begin(), nums.end(), [](auto a, auto b) {
            return a < b;
        });
        int total = 0;
        for (int i = 0; i < nums.size() - 2; ++i) {
            for (int j = i + 1; j < nums.size() - 1; ++j) {
                int left = j + 1, right = nums.size() - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (nums[mid] == nums[i] + nums[j]) {
                        right = mid - 1;
                    } else if (nums[mid] > nums[i] + nums[j]) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                total += right - j;
            }
        }
        return total;
    }
};

//int main() {
//    Solution s;
//    cout << s.triangleNumber({2, 2, 3, 4});
//    return 0;
//}