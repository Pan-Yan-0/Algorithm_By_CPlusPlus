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
    string removeDuplicateLetters(string s) {
        unordered_map<char,int> unorderedMap;
        for (int i = 0; i < s.size(); ++i) {
            unorderedMap[s[i]] += 1;
        }
        stack<char> rr;
        rr.push(s[0]);
        for (int i = 1 ; i < s.size(); ++i) {
            if (rr.top() == s[i]) continue;
            if (rr.top() < s[i]){
                rr.push(s[i]);
            } else{
                while (!rr.empty() && rr.top() > s[i] && unorderedMap[rr.top()] != 1 ){
                    rr.pop();
                }
                rr.push(s[i]);
            }
        }
        string ans;
        while (!rr.empty()){
            ans.push_back(rr.top());
            rr.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
//int main(){
//    Solution s;
//    cout << s.removeDuplicateLetters("");
//    return 0;
//}