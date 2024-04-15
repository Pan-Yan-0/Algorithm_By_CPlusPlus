//
// Created by 。 on 2024/4/6.
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
#include <limits>

using namespace std;

class TreeAncestor {
public:
    vector<vector<int>> tuoMap;
    unordered_map<int,int> unorderedMap;
    void process(int node,int n,int i){
        if (node == -1) return;
        tuoMap[node][i] = n;
        for (int j = 0; j < n; ++j) {
            process(tuoMap[node][j],n+1,i);
        }
    }
    TreeAncestor(int n, vector<int> parent) {
        tuoMap = vector<vector<int>>(n,vector<int>(n,-1));
        unorderedMap[0] = -1;

        for (int i = 1; i < n; ++i) {
            tuoMap[parent[i]][i] = 1;
            unorderedMap[i] = parent[i];

        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;

            }
        }

        for (int i = 0; i < tuoMap.size(); ++i) {
            for (int j = 0; j < tuoMap.size(); ++j) {
                cout << tuoMap[i][j] << " ";
            }
            cout << endl;
        }
    }

    int getKthAncestor(int node, int k) {
        for (int i = 0; i < k; ++i) {
            node = this->unorderedMap[node];
            if (node == -1) return node;
        }
        return node;
    }
};

//int main() {
//    TreeAncestor *obj = new TreeAncestor(7, {-1, 0, 0, 1, 1, 2, 2});
//    int param_1 = obj->getKthAncestor(3, 1);
//    cout << param_1;
//    return 0;
//}