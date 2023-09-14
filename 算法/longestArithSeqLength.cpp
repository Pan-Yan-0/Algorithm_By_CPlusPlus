//
// Created by 。 on 2023/9/11.
//

#include "longestArithSeqLength.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <valarray>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int method2(vector<int> arr,int difference){
        int ans = 0;
        unordered_map<int, int> dp;
        for (int v: arr) {
            dp[v] = dp[v - difference] + 1;
            ans = max(ans, dp[v]);
        }
        return ans;
    }
    int methods1(std::vector<int> nums) {
        int maxReturn = 1;
        unordered_map<int, bool> difs;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                difs[nums[i]-nums[j]] = true;
            }
        }
        for (const auto &item: difs){
            int i2 = method2(nums,item.first);
            maxReturn= max(i2,maxReturn);
        }
//        int dif = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
//        for (int i = -dif; i <= dif; ++i) {
//            int i1 = method2(nums, i);
//            maxReturn = max(i1,maxReturn);
//        }
        return maxReturn;
    }
    int methods(std::vector<int> nums) {
        int dif = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
        int maxReturn = 1;
        for (int i = -dif; i <= dif; ++i) {
            unordered_map<int, int> mapNum;
            int length = nums.size();
            int maxNum = -100;
            for (int j = 1; j < length; ++j) {
                mapNum[nums[j]] = mapNum[nums[j] - i] + 1;
                maxNum = max(mapNum[nums[j]], maxNum);
            }
            maxReturn = std::max(maxReturn, maxNum);
            cout << maxReturn << endl;
        }
        return maxReturn + 1;
    }

public:
    int longestArithSeqLength(vector<int> &nums) {

        return methods1(nums);
    }
};

//int main() {
//    //20,1,15,3,10,5,8
//    //9,4,7,2,10
//    Solution s;
//    vector<int> num;
//    num.push_back(9);
//    num.push_back(4);
//    num.push_back(7);
//    num.push_back(2);
//    num.push_back(10);
//    cout << s.longestArithSeqLength(num);
//    return 0;
//}