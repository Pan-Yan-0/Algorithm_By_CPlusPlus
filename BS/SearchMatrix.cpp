//
// Created by 。 on 2024/3/1.
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
    bool searchMatrix(vector<vector<int>> matrix, int target) {
        vector<int> topNum(matrix.size(), 0);
        for (int i = 0; i < matrix.size(); ++i) {
            topNum[i] = matrix[i][0];
        }
        int left = 0, right = topNum.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (topNum[mid] == target) return true;
            else if (topNum[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (right < 0)return false;
        if (left >= topNum.size() && target > matrix[matrix.size() - 1][matrix[matrix.size() - 1].size() - 1]){
            return false;
        }
        int k = right;
        left = 0,right = matrix[k].size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (matrix[k][mid] == target) return true;
            else if (matrix[k][mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return false;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.searchMatrix({{1,  3,  5,  7},
//                                   {10, 11, 16, 20},
//                                   {23, 30, 34, 60}}, 60);
//    return 0;
//}