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
    vector<string> shortestSubstrings(vector<string> arr) {
        vector<string > ans(arr.size(),"");
        vector<string > strArr(arr.size(),"");
        for (int i = 0; i < arr.size(); ++i) {
            bool getMin = false;
            for (int j = 1; j <= arr[i].size(); ++j) {
                for (int k = 0; k < arr[i].size() - j + 1; ++k) {
                    bool noHave = true;
                    strArr[i] = arr[i].substr(k,j);
                    // 遍历其他字符串是否有相同的
                    for (int l = 0; l < arr.size(); ++l) {
                        if (l == i) continue;
                        if (strArr[i].size() > arr[l].size()) continue;
                        for (int m = 0; m < arr[l].size() - j + 1; ++m) {
                            string temp = arr[l].substr(m,j);
                            bool equal = false;
                            if(strArr[i] == temp){
                                equal = true;
                            }
                            if (equal){
                                noHave = false;
                                break;
                            }
                        }
                    }
                    if (noHave){
                        getMin = true;
                        if (ans[i] > strArr[i] || ans[i] == ""){
                            ans[i] = strArr[i];
                        }
                    }
                    else strArr[i] = "";
                }
                if (getMin){
                    break;
                }
            }
        }
        return ans;
    }
};
//int main(){
//    Solution solution;
//    vector<string> substrings = solution.shortestSubstrings({"cab", "ad", "bad", "c"});
//    for (int i = 0; i < substrings.size(); ++i) {
//        cout << substrings[i] << " ";
//    }
//    return 0;
//}