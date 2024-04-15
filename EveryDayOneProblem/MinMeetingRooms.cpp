//
// Created by 。 on 2024/4/6.
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

class Solution {
public:
    int minMeetingRooms(vector<vector<int>> intervals) {
        int addSum[100000]={0};
        for (int i = 0; i < intervals.size(); ++i) {
            addSum[intervals[i][0]]++;
            addSum[intervals[i][1]]--;
        }
        vector<int> arr;
        arr.push_back(addSum[0]);
        int maxNum = 0;
        for (int i = 1; i < 100000; ++i) {
            arr.push_back(arr[i - 1] + addSum[i]);
            if (arr[i] > maxNum) maxNum = arr[i];
        }
        return maxNum;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.minMeetingRooms({{0,  30},
//                                      {5,  10},
//                                      {15, 20}});
//    return 0;
//}