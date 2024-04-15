//
// Created by 。 on 2024/4/7.
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
#include <limits>

using namespace std;

class Solution1 {
public:
    long long minOperationsToMakeMedianK(vector<int> nums, int k) {
        if (nums.size() == 1) return abs(nums[0] - k);

        sort(nums.begin(), nums.end());
        if (nums.size() == 2) return abs(nums[0] - k);
        int n = nums.size();
        int mid = nums[n / 2];
        if (mid == k) return 0;
        long long ans = 0;
        while (true) {
            if (mid > k) {
                nums[n / 2]--;
                ans++;
                if (nums[n / 2] < nums[n / 2 - 1]) {
                    swap(nums[n / 2], nums[n / 2 - 1]);
                }
            } else {
                nums[n / 2]++;
                ans++;
                if (nums[n / 2] > nums[n / 2 + 1]) {
                    swap(nums[n / 2], nums[n / 2 + 1]);
                }
            }
            mid = nums[n / 2];
            if (mid == k) break;
        }
        return ans;
    }
};
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int> nums, int k) {
        if(nums.size() == 1) return abs(nums[0] - k);

        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mid = nums[n / 2];
        long long ans = 0;

        // Start from the middle element and move towards k
        for (int i = n / 2; i >= 0 && nums[i] > k; --i) {
            ans += nums[i] - k;
        }
        for (int i = n / 2; i < n && nums[i] < k; ++i) {
            ans += k - nums[i];
        }

        return ans;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.minOperationsToMakeMedianK({2,5,6,8,5}, 4);
//    return 0;
//}