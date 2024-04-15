//
// Created by 。 on 2024/4/14.
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
    bool isPrime(int num) {
        if (num == 1)return false;
        if ( num == 2 || num == 3) return true;
        for (int i = 2; i < sqrt(num) + 1; ++i) {
            if (num % i == 0) return false;
        }
        return true;
    }

    int maximumPrimeDifference(vector<int> nums) {
        int left = 0, right = nums.size() - 1;
        bool canRet = true;
        while (left <= right) {
            canRet = true;
            if (!isPrime(nums[left])) {
                left++;
                canRet = false;
            }
            if (!isPrime(nums[right])) {
                right--;
                canRet = false;
            }
            if (canRet) return right - left;
        }
        return 0;
    }
};

//int main() {
//    Solution s;
//    cout << s.isPrime(3);
//    cout << s.maximumPrimeDifference({4,8,2,8});
//    return 0;
//}