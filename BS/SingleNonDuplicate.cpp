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
    int singleNonDuplicate(vector<int> nums) {
        int left = 0,right = nums.size() - 1;
        while (left < right){
            int mid = left + (right - left) / 2;
            if (mid == 0){
                return nums[mid];
            }
            if (nums[mid] == nums[mid - 1] || nums[mid] == nums[mid + 1]){
                if (nums[mid] == nums[mid - 1]){
                    if (mid % 2==0){
                        right = mid - 2;
                    }else{
                        left = mid + 1;
                    }
                }else{
                    if ((mid + 1) % 2 == 0){
                        right = mid - 1;
                    } else{
                        left = mid + 2;
                    }
                }
            }else{
                return nums[mid];
            }
        }
        return nums[left];
    }
};
//int main(){
//    Solution s;
//    cout << s.singleNonDuplicate({1,1,3,3,4,4,8,8,9});
//    return 0;
//}