//
// Created by 。 on 2024/3/10.
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
#include <queue>
#include <climits>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minimumBoxes(vector<int> apple, vector<int> capacity) {
        sort(capacity.begin(),capacity.end());
        int sum = 0;
        for (int i = 0; i < apple.size(); ++i) {
            sum += apple[i];
        }
        int k = 0;
        for (int i = capacity.size() - 1; i >= 0 ; --i) {
            k += capacity[i];
            if (k >= sum){
                return capacity.size() - i;
            }
        }
        return -1;
    }
};
//int main(){
//    Solution solution;
//    cout << solution.minimumBoxes({5,5,5},{2,4,2,7});
//    return 0;
//}