//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <unordered_set>
//#include <numeric>
//
//using namespace std;
//
//struct Edge {
//    int village1, village2, cost;
//    Edge(int v1, int v2, int c) : village1(v1), village2(v2), cost(c) {}
//};
//
//class Solution {
//public:
//    vector<int> parent;
//    int find(int i) {
//        if (parent[i] != i) parent[i] = find(parent[i]);
//        return parent[i];
//    }
//
//    void unionSet(int x, int y) {
//        int rootX = find(x);
//        int rootY = find(y);
//        if (rootX != rootY) {
//            parent[rootX] = rootY;
//        }
//    }
//
//    int minCostToRepair(vector<Edge>& edges, vector<Edge>& unSuit, int n) {
//        parent.resize(n);
//        iota(parent.begin(), parent.end(), 0); //并查集初始化
//
//        // 先将合格的路加入图中，不需要修复费用
//        for (Edge& edge : edges) {
//            int u = find(edge.village1), v = find(edge.village2);
//            if (u != v) {
//                unionSet(u, v); //合并两个村庄
//            }
//        }
//
//        // 对不合格的路线根据成本进行排序
//        sort(unSuit.begin(), unSuit.end(), [](const Edge &a, const Edge &b) {
//            return a.cost < b.cost;
//        });
//
//        // 修复不合格的路线
//        int totalCost = 0;
//        for (Edge& edge : unSuit) {
//            int u = find(edge.village1), v = find(edge.village2);
//            if (u != v) { //若两村庄不在一个连通分量中，修复这条路
//                totalCost += edge.cost;
//                unionSet(u, v);
//            }
//        }
//
//        // 最后检查所有村庄是否已经连通
//        int connectedComponents = 0;
//        for(int i = 0; i < n; ++i) {
//            if(parent[i] == i) {
//                connectedComponents++;
//            }
//        }
//
//        return connectedComponents == 1 ? totalCost : -1;
//    }
//};
//
//int main() {
//    int k;
//    scanf("%d,", &k);
//    vector<pair<int,int>> sales(k);
//    for (int i = 0; i < k; ++i) {
//        int n, c;
//        scanf("(%d,%d)", &n, &c);
//        sales[i] = {n,c};
//    }
//    Solution solution;
//    solution.minCostToRepair(sales);
//}
//
//
