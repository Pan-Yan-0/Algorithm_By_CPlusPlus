//
// Created by 。 on 2024/4/24.
//
#include "../theInclude.h"

class Solution {
public:
    int makeConnected(int n, vector<vector<int>> &connections) {
        if (connections.size() < n - 1) return -1;
        vector<int> p(n), rank(n, 1);
        iota(p.begin(),p.end(),0);
        function<int(int)> find = [&](int root) -> int {
            if (root == p[root]) return root;
            return p[root] = find(p[root]);
        };
        function<void(int, int)> Union = [&](int root1, int root2) -> void {
            int rootX = find(root1);
            int rootY = find(root2);
            if (rootX!=rootY){
                if (rank[rootX]>rank[rootY]) p[rootX] = rootY;
                else if (rank[rootX]<rank[rootY]) p[rootY] = rootX;
                else{
                    p[rootX] = rootY;
                    rank[rootY]+=1;
                }
            }
        };
        function<bool(int,int)> connected = [&](int root1,int root2)->bool {
            return find(root1) == find(root2);
        };
        for (int i = 0; i < connections.size(); ++i) {
            Union(connections[i][0],connections[i][1]);
        }
        unordered_map<int,bool> unorderedMap;
        for (int i = 0; i < n; ++i) {
            unorderedMap[find(i)] = true;
        }
        return unorderedMap.size()-1;
    }
};