//
// Created by 。 on 2024/4/8.
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
    int maxMinFunction(vector<int> arr,int ans) {
        int minAns = INT32_MAX;
        int n = arr.size() - 1;
        int count = 0;
        for (int i = 0; i < arr.size(); ++i) {
            count = 0;
            int maxNum = arr[i] + n + ans;
            int left = i, right = n;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] == maxNum) {
                    left = mid + 1;
                } else if (arr[mid] > maxNum) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            count = i + n - right;
            // if (arr[right] != maxNum) {
            //     count--;
            // }
            minAns = min(minAns,count);
        }
        return minAns;
    }

    int minOperations(vector<int> nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        vector<int> arrs;
        arrs.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i-1]){
                arrs.push_back(nums[i]);
            }
        }
        ans += nums.size() - arrs.size();
        // Violent Function
        ans += maxMinFunction(arrs,ans);
        return ans;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.minOperations({8,5,9,9,8,4});
//    return 0;
//}