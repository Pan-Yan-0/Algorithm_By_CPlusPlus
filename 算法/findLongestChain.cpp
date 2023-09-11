//
// Created by 。 on 2023/9/10.
//

#include "findLongestChain.h"

#include <iostream>
#include<vector>
#include<string>
#include<math.h>
#include <algorithm>

using namespace std;

class Solution {
private:
    int process(vector<vector<int>> pairs, int index, int lastNum) {
        if (pairs.size() == index) {
            return 1;
        }
        int num1;
        if (lastNum > pairs[index][0]) {
            num1 = process(pairs, index + 1, lastNum);
        } else {
            num1 = process(pairs, index + 1, pairs[index][1]) + 1;
        }
        int num2 = process(pairs, index + 1, lastNum);
        return max(num1, num2);
    }
    bool compare(vector<int> num1,vector<int> num2){
        if (num1[0] < num2[0]){
            return 1;
        } else{
            return 0;
        }
    }
    int DP(vector<vector<int>> pairs) {
        sort(pairs.begin(),pairs.end());
        int length = pairs.size();
        vector<int> dp(length, 1);
        for (int i = 1; i < length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (pairs[i][0] > pairs[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                } else {

                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
    int greedy(vector<vector<int>> pairs){
        sort(pairs.begin(), pairs.end());
        vector<int> arr;
        for (auto p : pairs) {
            int x = p[0], y = p[1];
            if (arr.size() == 0 || x > arr.back()) {
                arr.emplace_back(y);
            } else {
                // lower_bound
                int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
                arr[idx] = min(arr[idx], y);
            }
        }
        return arr.size();
    }
public:
    int findLongestChain(vector<vector<int>> &pairs) {
        return DP(pairs);
        //return process(pairs, 0, -10000);
    }
};

//  使用c++
//int main() {
//    Solution s;
//    vector<vector<int>> nums;
//    vector<int> num;
//    num.push_back(1);
//    num.push_back(2);
//    nums.push_back(num);
//    num.clear();
//    num.push_back(7);
//    num.push_back(8);
//    nums.push_back(num);
//    num.clear();
//    num.push_back(4);
//    num.push_back(5);
//    nums.push_back(num);
//    num.clear();
//    cout << s.findLongestChain(nums);
//    return 0;
//}