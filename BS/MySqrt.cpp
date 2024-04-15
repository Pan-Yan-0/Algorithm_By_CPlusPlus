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
    int mySqrt(int x) {
        if (x == 1 || x == 2) return 1;
        int left = 0,right = x / 2;
        while (left <= right){
            int mid = left + (right - left) /2 ;
            int temp = mid * mid;
            if(x == temp)return mid;
            else if (x > temp){
                left = mid + 1;
            } else{
                right = mid - 1;
            }
        }
        return right;
    }
};
//int main(){
//    Solution solution;
//    cout << solution.mySqrt(4);
//
//    return 0;
//}