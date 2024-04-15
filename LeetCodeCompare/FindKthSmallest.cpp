//
// Created by 。 on 2024/4/14.
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
#include <climits>

using namespace std;

class Solution1 {
public:
    // 巧妙但是k 过大
    long long findKthSmallest(vector<int> coins, int k) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> priorityQueue;
        for (int i = 0; i < coins.size(); ++i) {
            priorityQueue.push({coins[i], i});
        }
        long long lastPop = -1;
        while (k > 1) {
            pair<int, int> top = priorityQueue.top();
            priorityQueue.pop();
            priorityQueue.push({((top.first / coins[top.second]) + 1) * coins[top.second], top.second});
            if (lastPop == top.first) continue;
            lastPop = top.first;
            k--;
        }
        while (lastPop == priorityQueue.top().first) {
            pair<int, int> top = priorityQueue.top();
            priorityQueue.pop();
            priorityQueue.push({((top.first / coins[top.second]) + 1) * coins[top.second], top.second});
        }
        return priorityQueue.top().first;
    }
};

class Solution2 {
public:
    // 计算两个数的最大公约数
    long long gcd(long long a, long long b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    // 计算两个数的最小公倍数
    long long lcm(long long a, long long b) {
        // 先计算最大公约数，再相乘除以最大公约数，避免溢出
        return a / gcd(a, b) * b;
    }

    // 找到第 k 小的值
    long long findKthSmallest(vector<int> coins, int k) {
        /*
         * 本部分为去重操作
         * 使用容斥定理来解决权值问题，详细建议自己查查，因为是集合论内容，图可以很明显体现出来
         *
         * 非常好，你已经理解了容斥原理（没看的下面会看不懂）
         * 在集合论中，三维空间内（三个集合）我们的容斥定理，因为在两两相交的时候，我们是得删除重复部分
         * 但是在删除的过程中，我们发现三个相交部分被删除多了一次，我们需要加回来
         * 这就是为什么在奇数个元素权值为 1 ，偶数个元素权值为 -1
         * */
        // 存储每个组合的最小公倍数和贡献数量
        vector<pair<long long, int>> vp;

        // 构建所有可能的组合
        int n = coins.size();
        for (int i = 1; i < (1 << n); i++) {
            long long u = 0;
            int y = -1;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1)
                    u = (u == 0 ? coins[j] : lcm(u, coins[j])), y *= -1;
            }
            vp.emplace_back(u, y);
        }

        // 二分搜索
        long long l = 0, r = 1e18; // 初始化搜索范围
        while (l < r - 1) { // 当搜索范围缩小到相邻的两个数时结束循环
            long long m = (l + r) >> 1; // 计算中间值
            long long cnt = 0; // 计数小于等于目标值的数量
            for (auto [e, p]: vp) // 遍历所有组合
                cnt += m / e * p; // 计算小于等于 m 的数量
            if (cnt >= k) // 如果小于等于 m 的数量大于等于 k
                r = m; // 缩小搜索范围为左半部分
            else
                l = m; // 缩小搜索范围为右半部分
        }
        return r; // 返回第 k 小的值
    }
};

class Solution {
public:
    long long gcd(long long num1, long long num2) {
        if (num1 < num2) swap(num1, num2);
        while (num2) {
            num1 = num1 % num2;
            swap(num1, num2);
        }
        return num1;
    }

    long long lcd(long long num1, long long num2) {
        return num1 / gcd(num1, num2) * num2;
    }

    long long findKthSmallest(vector<int> coins, int k) {
        /*
          * 本部分为去重操作
          * 使用容斥定理来解决权值问题，详细建议自己查查，因为是集合论内容，图可以很明显体现出来
          *
          * 非常好，你已经理解了容斥原理（没看的下面会看不懂）
          * 在集合论中，三维空间内（三个集合）我们的容斥定理，因为在两两相交的时候，我们是得删除重复部分
          * 但是在删除的过程中，我们发现三个相交部分被删除多了一次，我们需要加回来
          * 这就是为什么在奇数个元素权值为 1 ，偶数个元素权值为 -1
          *
          * 使用集合论的知识来进行去重操作（所以说，算法好得数学好）
          * */
        vector<pair<int, int>> vp;
        int n = coins.size();
        for (int i = 1; i < (1 << n); ++i) {
            long long u = 0;
            int y = -1;
            for (int j = 0; j < n; ++j) {
                if (i >> j & 1) {
                    u = (u == 0 ? coins[j] : lcd(u, coins[j]));
                    y *= -1;
                }
            }
            vp.push_back({u, y});
        }
        long long l = 1, r = 10e18;
        while (l <= r) {
            long long mid = l + (r - l) / 2;
            long long count = 0;
            for (int i = 0; i < vp.size(); ++i) {
                auto [u,y] = vp[i];
                count += (mid / u * y);
            }
            if (count >= k){
                r = mid - 1;
            } else{
                l = mid + 1;
            }
        }
        return r;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.findKthSmallest({6, 5}, 1435065516);
//
//    return 0;
//}