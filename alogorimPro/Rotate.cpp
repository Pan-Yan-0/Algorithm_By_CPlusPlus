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
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size() - 1;
        for (int i = 0; i < (matrix.size()+1)/2; ++i) {
            for (int j = 0; j < (matrix[i].size()+1)/2; ++j) {
                int k = i,l = j;
                int temp = 0;
                for (int m = 0; m < 3; ++m) {
                    temp = matrix[k][l];

                    swap(k,l);
                    l = n - l;
                    matrix[k][l] = temp;
                }
            }
        }
    }
};