//
// Created by 。 on 2024/3/7.
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
    vector<int> divisibilityArray(string word, int m) {
        long lastMod = 0;
        int n = word.size();
        vector<int> ans(word.size(),0);
        for(int i = 0;i < word.size();i++){
            lastMod = lastMod * 10 + (word[i] - '0');
            lastMod = lastMod % m;
            if (lastMod == 0){
                ans[i] = 1;
            }
        }
        return ans;
    }
};

//int main() {
//    Solution solution;
//    vector<int> divisibilityArray = solution.divisibilityArray("998244353", 3);
//    for (int i = 0; i < divisibilityArray.size(); ++i) {
//        cout << divisibilityArray[i] <<" ";
//    }
//    return 0;
//}