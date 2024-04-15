//
// Created by 。 on 2024/3/4.
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
    vector<int> successfulPairs(vector<int> spells, vector<int> potions, long long success) {
        vector<int> returnArr;
        sort(potions.begin(),potions.end());
        for (int i = 0; i < spells.size(); ++i) {
            int left = 0,right = potions.size() - 1;
            while (left <= right){
                int mid = left + (right - left) / 2;
                if ((long long )spells[i] * potions[mid] >= success){
                    right = mid - 1;
                } else{
                    left = mid + 1;
                }
            }
            returnArr.push_back(potions.size() - left);
        }
        return returnArr;
    }
};

//int main() {
//    Solution solution;
//    vector<int> pairs = solution.successfulPairs({5, 1, 3}, {1, 2, 3, 4, 5}, 7ll);
//    for (int i = 0; i < pairs.size(); ++i) {
//        cout << pairs[i] <<" ";
//    }
//    return 0;
//}