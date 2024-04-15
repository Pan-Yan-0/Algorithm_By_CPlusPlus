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
    vector<int> arr;
    int target;

    int specialCase(int left, int right) {
        if (left > right) {
            if (left >= arr.size()) return INT32_MAX;
            return arr[left];
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                if (arr[left] < arr[right]) {
                    right = mid - 1;
                } else if (arr[left] > arr[right]) {
                    left = mid + 1;
                } else {
                    int i = specialCase(left, mid - 1);
                    int i1 = specialCase(mid + 1, right);
                    return min(i, i1);
                }
            } else if (arr[mid] > target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (left >= arr.size()) return INT32_MAX;
        return arr[left];
    }

    int findMin(vector<int> nums) {
        int left = 0, right = nums.size() - 1;
        target = nums[right];
        arr = nums;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {

                int i = specialCase(left, mid - 1);
                int i1 = specialCase(mid + 1, right);
                return min(i, i1);

            } else if (nums[mid] > target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        if (left >= nums.size()) return nums[0];
        return nums[left];
    }
};

//int main() {
//    Solution solution;
//    cout << solution.findMin({1, 3, 3});
//    return 0;
//}