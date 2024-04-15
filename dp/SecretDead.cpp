//
// Created by 。 on 2024/2/29.
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

class Solution{
public:
    int secretDead(vector<int> highs){
        vector<int> nD(highs.size() + 2,0);
        vector<int> jD(highs.size() + 2,0);
        for (int i = highs.size() - 1; i >= 0 ; --i) {
            nD[i] = highs[i] + jD[i+1];
            jD[i] = min(nD[i], min(nD[i+1],nD[i+2]));
        }
        return min(nD[0],jD[0]);
    }
};
//int main(){
//    Solution solution;
//    int n;
//    scanf("%d",&n);
//    if (n <= 2){
//        cout << 0;
//        return 0;
//    }
//    vector<int> arr;
//    for (int i = 0; i < n; ++i) {
//        int temp;
//        scanf("%d",&temp);
//        arr.push_back(temp);
//    }
//    cout << solution.secretDead(arr);
//    return 0;
//}