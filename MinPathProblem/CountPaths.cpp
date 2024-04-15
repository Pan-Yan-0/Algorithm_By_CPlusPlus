//
// Created by 。 on 2024/3/5.
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

using namespace std;

// 这个可以先行了解一下 Dijkstra 算法 https://blog.csdn.net/lbperfect123/article/details/84281300
// 这里是使用了优先队列对最初的Dijkstra 算法进行优化，来找到下一次遍历的节点是哪个时间复杂度从O(n)变到O(logn)
// 还有题目的：你想知道 从路口 0 出发到达路口 n - 1 的方案数。
// 在使用 Dijkstra 算法期间我们就可以维护一个dp表（实际上这个不算得上动规吧，应该可能大概）
// 这个dp表 ， 表示花费 最少时间从 路口 0 出发到 某个路口的 方案数
// dis 数组表示路口 0 到 某一个路口的最短路径
// 在使用 Dijkstra 算法的时候，假如我们遍历到第i节点的时候，dis[i] + (i到j的距离) < dis[j]
// 要更新到 j 这个路口的最短路径值，理应有dp[j] = dp[i]
// 假如dis[i] + (i到j的距离) == dis[j] 说明从i到j也是最短的，故应该dp[j] += dp[i]
class Solution {
public:

    void printTwoMatrix(vector<vector<int>> matrix) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[i].size(); ++j) {
                cout << matrix[i][j] << "\t";
            }
            cout << endl;
        }
    }

    const static int mod = 1e9 + 7;

    int countPaths(int n, vector<vector<int>> roads) {
        // pair<int,int> 第一个int是节点 ，第二个int是到该节点的距离
        vector<vector<pair<int, int>>> matrix(n,vector<pair<int,int>>());
        for (int i = 0; i < roads.size(); ++i) {
            int x = roads[i][0], y = roads[i][1], w = roads[i][2];
            matrix[x].emplace_back(y, w);
            matrix[y].emplace_back(x, w);
        }
        // 存 0 节点到其他节点的最短距离
        vector<long long> dis(n, LLONG_MAX);
        // 存 有几条最短路可以到dp[i]的 i 节点
        vector<int> dp(n, 0);
        // 利用优先队列来获取最小值是哪一个
        // 内部使用堆的方式进行搜索
        // 其中priority_queue
        // <pair<long long ,int>这个是内部存储的是什么类型的元素
        // ,vector<pair<long long ,int>>,// 如何存储元素
        // greater<pair<long long ,int>>> q;// 如何比较相对应的大小
        // （此处的pair<>（内置有如何比较大小，即是比较pair.first的大小并且从））
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
        //把起始点扔进优先队列中
        q.emplace(0, 0);
        // 初始化 dp 和 dis 表
        dp[0] = 1;
        dis[0] = 0;
        // 所有的都遍历一遍就跳出循环
        while (!q.empty()) {
            // 用自动类似long long t = q.top().first ;int x = q.top().second;
            auto [t, x] = q.top();
            q.pop();
            // 此处的if是把一些无用数据处理掉，加快算法进程
            // 什么是无用的数据，怎么产生的？
            // 这个是产生于下面的for循环中的这句话q.emplace(dis[node],node);
            // 此处添加进去的数据也仅仅是为了找到下一次应该从哪个地方哪个节点开始遍历
            // 这个可以先行了解一下 Dijkstra 算法 https://blog.csdn.net/lbperfect123/article/details/84281300
            // 了解完之后，我们知道没有使用优先队列的话是暴力遍历我们这里的 dis 数组找到最小值，再遍历这个节点更新 dis 数组
            // 优先队列就是优化了这个暴力遍历 dis 数组的过程，优先队列里边使用了 堆的方法 快速的找到了下一次遍历的节点
            // 但是其中我们加入了一些不是下一次遍历的节点，导致出现一些 无用数据 ，这些无用数据虽然说并不影响后边的操作
            // 但是加上这个if判断可以加快速度
            // 这里有一些人也是喜欢使用mark标记本处已经达到最小情况（即已经开始遍历了）
            // 这样的优先队列可以看 https://oi-wiki.org/graph/shortest-path/#%E5%AE%9E%E7%8E%B0_2
            if (t > dis[x]) continue;
            for (const auto [node, w]: matrix[x]) {
                // 假如需要更新，即本次遍历更新了dis（最短路径数组）
                if (dis[node] > t + w) {
                    dis[node] = t + w; // 更新最短路径的值
                    dp[node] = dp[x]; // 更新最短路径条数
                    q.emplace(dis[node], node); // 将其加入到优先队列中
                } else if (dis[node] == t + w) {
                    // 假如相等，就把路径条数相加
                    dp[node] = (dp[node] + dp[x]) % mod;
                }
            }
        }
        return dp[n - 1];
    }
};
//
//int main() {
//    Solution solution;
//    cout << solution.countPaths(7, {{0, 6, 7},
//                                    {0, 1, 2},
//                                    {1, 2, 3},
//                                    {1, 3, 3},
//                                    {6, 3, 3},
//                                    {3, 5, 1},
//                                    {6, 5, 1},
//                                    {2, 5, 1},
//                                    {0, 4, 5},
//                                    {4, 6, 2}});
//
//    return 0;
//}