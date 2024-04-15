//
// Created by 。 on 2024/4/9.
//
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <queue>
#include <cstring>
#include <algorithm>
#include <list>

using namespace std;

class Solution {
public:
    int maximumCount(vector<int> nums) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= 0) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int minNum = left;
        right = nums.size() - 1;
        while (left <= right){
            int mid = left + (right - left ) / 2;
            if (nums[mid] <= 0){
                left = mid + 1;
            } else{
                right = mid - 1;
            }
        }
        int maxNum = nums.size() - left;
        return max(maxNum,minNum);
    }
};

//int main() {
//    Solution solution;
//    cout << solution.maximumCount({-3,-2,-1,0,0,1,2});
//    return 0;
//}