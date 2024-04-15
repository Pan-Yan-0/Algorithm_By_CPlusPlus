//
// Created by 。 on 2024/2/23.
//
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    int search(vector<int> nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = (left + right) / 2;
            if (target == nums[mid]) return mid;
            if (target < nums[mid]) right = mid - 1;
            else{
                left = mid + 1;
            }
        }
        return -1;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.search({5}, 5);
//    return 0;
//}