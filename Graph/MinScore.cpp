//
// Created by 。 on 2024/4/24.
//
#include "../theInclude.h"
FILE *a;
class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int> bits;
        while (x) {
            bits.push_back(x % 2);
            x /= 2;
        }
        while (bits.size() < 64) bits.push_back(0);
        int num = 1;
        if (n == 1) return x;
        int i = x;
        for (int j = 0; j < bits.size(); ++j) {
            if (bits[j]) {
                i += pow(2, j);
                continue;
            } else {
                num *=2;

                if (num >= n){
                    if (num == n){
                        return i;
                    } else{
                        int temp = num - n;
                        int l = pow(2,i);
                        //使用循环寻找比上一次大temp个的数 ， 并且返回相应的值
                        for (int k = i; k >= 0; --k) {
                            if (bits[k]){
                                l += pow(2,k);
                            } else{

                            }
                        }
                        return l;
                    }
                }
                i += pow(2,j);
            }
        }
        // 外部的返回是不可能存在的，必定在上边的循环中返回
        return 0;
    }
};