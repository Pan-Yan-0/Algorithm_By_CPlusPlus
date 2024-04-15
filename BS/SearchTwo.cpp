//
// Created by 。 on 2024/3/1.
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
    int RightPosition(vector<int> nums, int target) {
        int index = nums.size() - 1;
        while (index >= 0) {
            if (nums[index] == target) {
                return index;
            }
        }
        return -1;
    }

    int otherFunction(vector<int> nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) {
                if (nums[right] < nums[mid] && nums[right] >= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                if (nums[left] >= nums[mid] && nums[left] <= target && nums[left] > nums[right]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }

    int search(vector<int> nums, int target) {
        return otherFunction(nums, target);
        int left = 0, right = nums.size() - 1;
        if (target < nums[right]) {
            return RightPosition(nums, target);
        }
        while (right >= 0) {
            if (nums[right] < target) {
                right--;
            } else if (nums[right] == target) {
                return right;
            } else {
                break;
            }

        }
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) right = mid - 1;
            else left = mid + 1;
        }
        return -1;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.search({4, 5, 6, 7, 8, 1, 2, 3}, 3);
//    return 0;
//}