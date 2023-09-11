//
// Created by 。 on 2023/9/11.
//

#include "longestSubsequence.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
private:
    int method(vector<int> arr,int difference){
        int ans = 0;
        unordered_map<int, int> dp;
        for (int v: arr) {
            dp[v] = dp[v - difference] + 1;
            ans = max(ans, dp[v]);
        }
        return ans;
    }
    int method1(vector<int> arr,int difference){
        int length = arr.size();
        vector<int> dp(length, 1);
        for (int i = 1; i < length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (arr[i] - difference == arr[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        return method(arr,difference);
    }

};

int main() {
    Solution s;
    vector<int> num;
    num.push_back(1);
    num.push_back(5);
    num.push_back(6);
    num.push_back(7);
    num.push_back(5);
    num.push_back(3);
    num.push_back(4);
    num.push_back(2);
    num.push_back(1);
    int difference = -2;
    cout << s.longestSubsequence(num, difference);
    return 0;
}