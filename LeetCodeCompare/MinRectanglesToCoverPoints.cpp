//
// Created by 。 on 2024/4/13.
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
#include <stack>

using namespace std;

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>> points, int w) {
        sort(points.begin(), points.end());
        int ans = 0;
        for (int i = 0; i < points.size(); ++i) {
            int jump = points[i][0] + w;
            int left = i + 1, right = points.size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (points[mid][0] <= jump) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
            i = right;
            ans++;
        }
        return ans;
    }
};

//int main() {
//    Solution s;
//    cout << s.minRectanglesToCoverPoints({{2, 1},
//                                  {1, 0},
//                                  {1, 4},
//                                  {1, 8},
//                                  {3, 5},
//                                  {4, 6},{2,4}}, 1);
//    return 0;
//}