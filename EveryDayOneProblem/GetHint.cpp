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
    string getHint(string secret, string guess) {
        unordered_map<int, vector<int>> secretMap, guessMap;
        for (int i = 0; i < secret.size(); ++i) {
            secretMap[secret[i] - '0'].push_back(i);
            guessMap[guess[i] - '0'].push_back(i);
        }
        int cow = 0, bulls = 0;
        for (auto item: guessMap) {
            if (secretMap[item.first].empty()) continue;
            auto size1 = secretMap[item.first].size();
            auto size2 = item.second.size();
            if (size1 >= size2) {
                cow += size2;
            } else {
                cow += size1;
            }
            int s = 0, g = 0;
            while (s < size1 && g < size2) {
                auto sNum = secretMap[item.first][s];
                auto gNum = item.second[g];
                if (sNum == gNum){
                    bulls++;
                    cow--;
                    s++;
                    g++;
                } else if (sNum > gNum){
                    g++;
                }else{
                    s++;
                }
            }
        }
        string basicString = to_string(cow);
        string string1 = to_string(bulls);
        string ans = string1 + "A" + basicString +"B";
        return ans;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.getHint("1807", "7810");
//    return 0;
//}