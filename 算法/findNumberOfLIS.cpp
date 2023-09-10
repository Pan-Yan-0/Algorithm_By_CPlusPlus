//
// Created by 。 on 2023/9/9.
//

#include "findNumberOfLIS.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int> &nums) {
        vector<int> dp;
        vector<int> recode;
        dp.push_back(nums[0]);
        recode.push_back(1);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] > dp.back()) {
                dp.push_back(nums[i]);
                recode.push_back(1);
            } else{
                int left = 0,right = dp.size()-1;
                while (left < right){
                    int mid = (left + right) / 2;
                    if (nums[i] > dp[mid]) left = mid + 1;
                    else right = mid;
                }
                dp[right] = nums[i];
                recode.back()+=recode[right];
            }
        }
        return recode.back();
    }
};

//int main() {
//    Solution s;
//    vector<int> nums;
//    nums.push_back(1);
//    nums.push_back(3);
//    nums.push_back(5);
//    nums.push_back(4);
//    nums.push_back(7);
////    nums.push_back(1);
////    nums.push_back(3);
////    nums.push_back(5);
////    nums.push_back(4);
////    nums.push_back(7);
//    cout << s.findNumberOfLIS(nums);
//    return 0;
//}