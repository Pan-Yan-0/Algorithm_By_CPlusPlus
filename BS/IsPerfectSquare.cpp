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
    int maxK = 46341;
    bool isPerfectSquare(int num) {
        if (num == INT32_MAX) return false;
        int left = 0,right = maxK;
        while (left <= right){
            long mid = left + (right - left) /2 ;
            long temp = mid * mid;
            if (temp == num) return true;
            else if(temp > num ){
                right = mid - 1;
            } else{
                left = mid + 1;
            }
        }
        return false;
    }
};
//int main(){
//    Solution solution;
//    cout << solution.isPerfectSquare(3);
//    return 0;
//}