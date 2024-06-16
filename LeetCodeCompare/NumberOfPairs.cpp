//
// Created by 。 on 2024/5/26.
//
#include "../theInclude.h"
class Solution {
public:
    bool isPrime(int num) {
        // 特殊情况处理：小于等于 1 的数不是素数
        if (num <= 1) {
            return false;
        }
        // 对于大于 2 的数，如果其能被 2 整除，那么它不是素数
        if (num > 2 && num % 2 == 0) {
            return false;
        }
        // 从 3 开遍历到 sqrt(num)，如果在这个范围内存在能整除 num 的数，则 num 不是素数
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) {
                return false;
            }
        }
        // 如果上述条件都不满足，则 num 是素数
        return true;
    }
    long long numberOfPairs(vector<int>nums1, vector<int> nums2, int k) {
        long long ans = 0;
        int maxNum = 0;
        int mapNum1[1000007] = {0};
        for (int i = 0; i < nums2.size(); ++i) {
            nums2[i] *= k;
        }
        for (int i : nums1) {
            mapNum1[i]++;

            maxNum = max(i,maxNum);
        }
        for (int & i : nums2) {
            int temp = i;
            while (temp <= maxNum) {
                ans+=mapNum1[temp];
                temp+=i;
            }
        }
        return ans;
    }
};