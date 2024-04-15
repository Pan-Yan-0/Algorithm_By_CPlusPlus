//
// Created by 。 on 2024/4/10.
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
//    string removeKdigits(string num, int k) {
//
//        stack<char> rr;
//        string ans;
//
//        priority_queue<char, vector<char>, greater<char>> priorityQueue;
//        int n = num.size();
//        int need = n - k;
//        if (need==0) return "0";
//        for (int i = 0; i <= n - need; ++i) {
//            priorityQueue.push(num[i]);
//        }
//        for (int i = n - need + 1; i < n; ++i) {
////            ans.push_back(priorityQueue.top());
////            // 顺序问题
////            priorityQueue.pop();
////            priorityQueue.push(num[i]);o
//
//        }
//        ans.push_back(priorityQueue.top());
//        return ans;
//    }
    string removeKdigits(string num, int k) {
        stack<char> rr;
        rr.push(num[0]);
        int n = num.size();
        int need = n - k;
        for (int i = 1; i < num.size(); ++i) {
            if (n - (need - rr.size()) <= i) {
                rr.push(num[i]);
            } else {
                while ((!rr.empty()) && rr.top() >= num[i] && n - (need - rr.size()) > i) {
                    rr.pop();
                }
                rr.push(num[i]);
            }
        }
        string ans;
        while (!rr.empty()) {
            ans.push_back(rr.top());
            rr.pop();
        }
        for (int i = ans.size() - 1; i >= 0 ; --i) {
            if (ans[i] == '0') ans.pop_back();
            else break;
        }
        reverse(ans.begin(),ans.end());
        if (ans.empty()) return "0";
        return ans;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.removeKdigits("1432219", 3);
//    return 0;
//}