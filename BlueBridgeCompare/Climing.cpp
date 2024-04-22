//
// Created by 。 on 2024/4/20.
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
#include <climits>
#include <numeric>

using namespace std;
class Solution{
public:
    //4 5 6 49
    int climing(vector<int> high,int p,int q){
        sort(high.begin(),high.end());
        unordered_map<int,int> count;
        for (int i = 0; i < high.size(); ++i) {
            count[high[i]]++;
        }

    }
};
//int main() {
//    int n, p, q;
//    cin >> n >> p >> q;
//    vector<int> arr(n, 0);
//    for (int i = 0; i < n; ++i) {
//        scanf("%d", &arr[i]);
//    }
//    return 0;
//}