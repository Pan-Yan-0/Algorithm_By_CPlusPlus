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
    bool isValid(string s) {
        stack<char> rr;
        rr.push(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '[' || s[i] == '{' || s[i] == '('){
                rr.push(s[i]);
            } else{
                char top = rr.top();
                if (top == '[' && s[i] != ']') return false;
                else if (top=='{'&&s[i] !='}') return false;
                else if (top == '('&&s[i]!=')') return false;
            }
        }
        if (rr.empty()) return true;
        else return false;
    }
};
//int main(){
//    Solution solution;
//    cout << solution.isValid("");
//    return 0;
//}