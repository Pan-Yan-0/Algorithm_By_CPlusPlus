//
// Created by 。 on 2024/3/17.
//
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    long long minimumMoves(std::vector<int> nums, int k, int maxChanges) {
        int n = nums.size();
        std::vector<int> ones;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) ones.push_back(i);
        }

        int left = 0, right = ones.size() - 1;
        long long cost = 0;
        while (right < ones.size()) {
            int mid = (left + right) / 2;
            int count = right - mid + 1;
            int median = ones[mid];
            int movesToLeft = median - mid;
            int movesToRight = (count - 1) - movesToLeft;
            long long curCost = 0;
            if (movesToLeft <= maxChanges) {
                curCost += (long long) movesToLeft * movesToLeft;
                maxChanges -= movesToLeft;
            } else {
                curCost += (long long) maxChanges * maxChanges;
                maxChanges = 0;
                curCost += (long long) (movesToLeft - maxChanges) * (movesToLeft - maxChanges);
            }
            if (movesToRight > maxChanges) {
                right = mid - 1;
                continue;
            }
            curCost += (long long) movesToRight * movesToRight;
            cost = (cost == 0) ? curCost : std::min(cost, curCost);
            left = mid + 1;
            right = left;
        }
        return cost;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.minimumMoves({1, 1, 0, 0, 0, 1, 1, 0, 0, 1}, 3, 1);
//    return 0;
//}