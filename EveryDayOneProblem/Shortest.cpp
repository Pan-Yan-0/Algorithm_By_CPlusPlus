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

//
//class WordDistance {
//public:
//    vector<string> wordsdict;
//
//    WordDistance(vector<string> wordsDict) {
//        for (int i = 0; i < wordsDict.size(); i++) {
//            wordsdict.emplace_back(wordsDict[i]);
//        }
//    }
//
//    int shortest(string word1, string word2) {
//        int index1 = -1,index2 = -1;
//        int ans = INT32_MAX;
//        for (int i = 0; i < wordsdict.size(); ++i) {
//            if (wordsdict[i] == word1){
//                index1 = i;
//            }
//            if (wordsdict[i] == word2){
//                index2 = i;
//            }
//            if (index1 == -1 || index2 == -1) continue;
//            ans = min(ans, abs(index1 - index2));
//        }
//        return ans;
//    }
//};
class WordDistance {
public:
    unordered_map<string, vector<int>> wordsdict;

    WordDistance(vector<string> wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            string word = wordsDict[i];
            wordsdict[word].emplace_back(i);
        }
    }

    int shortest(string word1, string word2) {
        vector<int> index1 = wordsdict[word1];
        vector<int> index2 = wordsdict[word2];
        int i = 0, j = 0;
        int ans = INT32_MAX;
        while (i < index1.size() && j < index2.size()) {
            ans = min(ans, abs(index1[i]-index2[j]));
            if (index1[i] < index2[j]){
                i++;
            }else {
                j++;
            }
        }
        return ans;
    }
};

//int main() {
//    WordDistance *s = new WordDistance({"practice","makes","perfect","coding","makes"});
//    int param_1 = s->shortest("makes", "coding");
//    cout << param_1;
//    return 0;
//}