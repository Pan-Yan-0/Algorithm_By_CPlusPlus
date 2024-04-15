//
// Created by 。 on 2024/3/8.
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
#include <queue>
#include <climits>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    int twoSumLessThanK(vector<int> nums, int k) {
        sort(nums.begin(), nums.end());
        //int left = 0, right = nums.size() - 1;
//        while (left <= right) {
//            int mid = left + (right - left) / 2;
//            if (nums[mid] == k) {
//                right = mid - 1;
//                break;
//            } else if (nums[mid] > k) {
//                right = mid - 1;
//            } else {
//                left = mid + 1;
//            }
//        }
//        if (right <= 0) {
//            return -1;
//        }
        int l = 0, r = nums.size() - 1;
        int ans = INT32_MIN;
        while (l < r){
            int temp = nums[l] + nums[r];
            if (temp < k){
                l++;
                ans = max(ans,temp);
            } else{
                r--;
            }
        }
        return ans;
    }
};
//
//int main() {
//    Solution s;
//    cout << s.twoSumLessThanK({1,4,7,9,11,14}, 2);
//    return 0;
//}