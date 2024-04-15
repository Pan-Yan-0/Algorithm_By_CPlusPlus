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
    int searchInsert(vector<int> nums, int target) {
        int left = 0,right = nums.size() - 1;
        while (left <= right){
            int mid = (left + right) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }
};

//int main(){
//    Solution solution;
//    solution.searchInsert({1,3,5,6},7);
//    return 0;
//}