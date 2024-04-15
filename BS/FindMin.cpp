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
    int findMin(vector<int> nums) {
        int left = 0, right = nums.size() - 1,target = nums[right];
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) break;
            else if(nums[mid] > target){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        if (left >= nums.size()) return nums[0];
        return nums[left];
    }
};

//int main() {
//    Solution solution;
//    cout << solution.findMin({3});
//    return 0;
//}