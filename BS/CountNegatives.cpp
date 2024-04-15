//
// Created by 。 on 2024/2/26.
//
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int>> grid) {
        int sum = 0;
        for (int i = 0; i < grid.size(); ++i) {
            int left = 0, right = grid.size() - 1;
            while (left < right) {
                int mid = (left + right) / 2;
                if (grid[i][mid] == 0) left = mid;
                if (grid[i][mid] < 0) right = mid - 1;
                else {
                    left = mid + 1;
                }
            }
            if (left >= grid[i].size()) sum += grid[i].size();
            else {
                sum += grid[i].size() - left;
            }
        }
        return sum;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.countNegatives({{5,  3,  2,  0},
//                                     {3,  2,  1,  -1},
//                                     {1,  1,  -1, -2},
//                                     {-1, -1, -2, -3}});
//    return 0;
//}