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
    int arrangeCoins(int n) {
        int left = 0, right = n;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long temp =   (mid + 1)*mid / 2;
            if (n == temp) return (int)mid;
            else if (n > temp) {
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return right;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.arrangeCoins(5);
//
//    return 0;
//}