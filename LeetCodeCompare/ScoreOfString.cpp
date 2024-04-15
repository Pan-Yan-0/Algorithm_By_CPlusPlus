//
// Created by 。 on 2024/4/13.
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
    int scoreOfString(string s) {
        int sum = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            sum += abs(s[i] - s[i+1]);
        }
        return sum;
    }
};
//int main(){
//    Solution solution;
//    cout << solution.scoreOfString("hello");
//    return 0;
//}