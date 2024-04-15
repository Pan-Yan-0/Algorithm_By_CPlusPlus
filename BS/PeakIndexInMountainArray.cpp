//
// Created by 。 on 2024/3/2.
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
    int check(vector<int> vector1, int mid) {
        if (vector1[mid + 1] > vector1[mid] && vector1[mid - 1] < vector1[mid]) {
            return -1;
        }else if (vector1[mid + 1] < vector1[mid] && vector1[mid - 1] > vector1[mid]){
            return 1;
        }else{
            return 0;
        }
    }

    int peakIndexInMountainArray(vector<int> arr) {
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mid == 0) {
                return arr[mid] > arr[mid + 1] ? mid : mid + 1;
            }
            int case1 = check(arr, mid);
            if (case1 == 0) return arr[mid];
            else if (case1 == -1) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return arr[left] > arr[right] ? left : right;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.peakIndexInMountainArray({0, 1, 0});
//    return 0;
//}