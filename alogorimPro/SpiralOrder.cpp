//
// Created by 。 on 2024/4/9.
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
    vector<pair<int, int>> step = {{1,  0},
                                   {0,  1},
                                   {-1, 0},
                                   {0,  -1}};
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        int i = 0, j = 0;
        vector<vector<bool>> mark(matrix.size(), vector<bool>(matrix[0].size(), false));
        int n = matrix.size() * matrix[0].size();
        int choice = 0;
        vector<int> ans;
        while (n != 0) {
            int a = step[choice].first, b = step[choice].second;
            if (i + a < 0 || i + a >= matrix[0].size() || j + b < 0 || j + b >= matrix.size() || mark[i + a][j + b]) {
                choice = (choice + 1) % 4;
            } else {
                i += a;
                j += b;
                ans.push_back(matrix[i][j]);
                n--;
            }
        }
        return ans;
    }
};

//int main() {
//    return 0;
//}