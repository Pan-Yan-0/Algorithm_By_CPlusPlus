//
// Created by 。 on 2024/3/6.
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
    int shortestDistance(vector<string> wordsDict, string word1, string word2) {
        int index1 = -1, index2 = -1, minNum = INT32_MAX;
        for (int i = 0; i < wordsDict.size(); ++i) {
            if (wordsDict[i] == word1) {
                index1 = i;
            } else if (wordsDict[i] == word2) {
                index2 = i;
            }
            if (index1 == -1 || index2 == -1) continue;
            minNum = min(minNum, abs(index1 - index2));

        }
        return minNum;

    }
};

//int main() {
//    Solution solution;
//    cout << solution.shortestDistance({"practice", "makes", "perfect", "coding", "makes"},
//                                      "coding", "practice");
//    return 0;
//}
