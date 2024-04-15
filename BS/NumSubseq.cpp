//
// Created by 。 on 2024/3/5.
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
    static constexpr int MAX_N = int(1E5) + 5;
    int POW2[MAX_N];
    void powCaculation(){
        POW2[0] = 1;
        for (int i = 1; i < MAX_N; ++i) {
            POW2[i] = (int)((long long )(POW2[i-1] * 2) % 1000000007);
        }

    }
    int numSubseq(vector<int> nums, int target) {
        powCaculation();
        sort(nums.begin(), nums.end());
        int total = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int left = i, right = nums.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (nums[mid] + nums[i] <= target) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            int temp = max(right - i, 0);
            if (right < i || nums[right] * 2 > target && temp == 0) continue;
            total = (total +  POW2[temp]) % 1000000007;
        }
        return total;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.numSubseq(
//            {14, 4, 6, 6, 20, 8, 5, 6, 8, 12, 6, 10, 14, 9, 17, 16, 9, 7, 14, 11, 14, 15, 13, 11, 10, 18, 13, 17, 17,
//             14, 17, 7, 9, 5, 10, 13, 8, 5, 18, 20, 7, 5, 5, 15, 19, 14}, 22);
//    return 0;
//}