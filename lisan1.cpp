#include "theInclude.h"

using namespace std;

struct Edge {
    int village1, village2, cost;

    Edge(int v1, int v2, int c) : village1(v1), village2(v2), cost(c) {}
};
unordered_map<int, pair<int, int>> village_map;
vector<vector<int>> roadNote;

class Solution {
public:
    vector<int> parent;

    int find(int i) {
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }

    void unionSet(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            parent[rootX] = rootY;
        }
    }

    void minCostToRepair(vector<Edge> &edges, vector<Edge> &unSuit, int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0); //并查集初始化

        // 先将合格的路加入图中，不需要修复费用
        for (Edge &edge: edges) {
            int u = find(edge.village1), v = find(edge.village2);
            if (u != v) {
                unionSet(u, v); //合并两个村庄
            }
        }

        // 对不合格的路线根据成本进行排序
        sort(unSuit.begin(), unSuit.end(), [](const Edge &a, const Edge &b) {
            return a.cost < b.cost;
        });

        // 修复不合格的路线
        int totalCost = 0;
        vector<int> pairNode;
        for (Edge &edge: unSuit) {
            int u = find(edge.village1), v = find(edge.village2);
            if (u != v) { //若两村庄不在一个连通分量中，修复这条路
                totalCost += edge.cost;
                unionSet(u, v);
                pairNode.push_back(roadNote[edge.village1][edge.village2]);
            }
        }
        cout << pairNode.size() << ",";
        cout << "{";
        if (pairNode.size() == 0) {
            cout << "}" << "," << totalCost;
            return;
        }
        cout << pairNode[0];
        for (int i = 1; i < pairNode.size(); ++i) {
            cout << "," << pairNode[i];
        }
        cout<<"}" << "," << totalCost;
    }
};



void init() {
    village_map[1] = {0, 1};
    village_map[2] = {0, 2};
    village_map[3] = {1, 2};
    village_map[4] = {1, 'H' - 'A'};
    village_map[5] = {2, 3};
    village_map[6] = {2, 4};
    village_map[7] = {2, 'H' - 'A'};
    village_map[8] = {3, 4};
    village_map[9] = {3, 5};
    village_map[10] = {3, 'G' - 'A'};
    village_map[11] = {3, 'H' - 'A'};
    village_map[12] = {4, 5};
    village_map[13] = {5, 'G' - 'A'};
    village_map[14] = {'G' - 'A', 'H' - 'A'};
}

//int main() {
//    int k;
//    scanf("%d,", &k);
//    init();
//    unordered_map<int, int> unorderedMap;
//    for (int i = 0; i < k; ++i) {
//        int n, c;
//        scanf("(%d,%d)", &n, &c);
//        unorderedMap[n] = c;
//    }
//    roadNote = vector<vector<int>>(8,vector<int>(8,0));
//    vector<Edge> arr1, arr2;
//    for (const auto &item: village_map) {
//        roadNote[item.second.first][item.second.second] = item.first;
//        roadNote[item.second.second][item.second.first] = item.first;
//        if (unorderedMap[item.first] >= 1) {
//            arr2.push_back(Edge(item.second.first, item.second.second, unorderedMap[item.first]));
//        } else {
//            arr1.push_back(Edge(item.second.first, item.second.second, unorderedMap[item.first]));
//        }
//    }
//
//    Solution solution;
//    solution.minCostToRepair(arr1, arr2, 8);
//}


