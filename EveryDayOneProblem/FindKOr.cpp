//
// Created by 。 on 2024/3/6.
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
    int findKOr(vector<int> nums, int k) {
        vector<int> arr(32,0);
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < 32; ++j) {
                int temp = nums[i];
                arr[j] = arr[j] + ((temp >> j) & 1);
            }
        }
        int sum = 0;
        for (int i = 0; i < arr.size(); ++i) {
            if (arr[i] >= k){
                sum += 1 << i;
            }
        }
        return sum;
    }
};
//int main(){
//    Solution solution;
//    cout << solution.findKOr({7,12,9,8,9,15},4);
//    return 0;
//}

