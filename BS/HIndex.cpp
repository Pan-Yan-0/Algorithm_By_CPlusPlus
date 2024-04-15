//
// Created by 。 on 2024/3/2.
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
    int hIndex(vector<int> citations) {
        int left = 0, right = citations.size() - 1;
        int n = citations.size();
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int target = n - mid;
            if (citations[mid] == target) return target;
            else if (citations[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (right < 0) {
            return citations.size();
        }
        int max1 = max(citations[right], (int) (citations.size() - left));
        return max1 > n - right ? n - right : max1;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.hIndex({1, 4, 7, 9});
//    return 0;
//}