//
// Created by 。 on 2024/4/19.
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
#include <numeric>

using namespace std;

class Solution {
    typedef long long ll;
public:
    int minSkips(vector<int> dist, int speed, int hoursBefore) {
        int n = dist.size();
        /**
         * @param index dist的哪个下标
         * @param count 在哪个时间块
         * @param countLess 当前时间块所剩的时间
         * @return ans (int) 返回最少jump次数
         */
        function<int(int, int, int)> process = [&](int index, int count, int countLess) {
            if (count > hoursBefore) return 1000;
            if (index == n - 1) {
                if (dist[index] <= (hoursBefore - count) * speed + countLess) {
                    return 0;
                }
            }
            if (dist[index] > (hoursBefore - count) * speed + countLess) {
                return 1000;
            }
            int k = dist[index] - countLess;

            int temp = k < 0 ? 0 : ((dist[index] - countLess) / speed + 1);
            int temp2 = (abs(dist[index] - countLess) % speed);
            int num1 = process(index + 1, count + (temp2 == 0 ? temp : temp + 1), speed);
            int num2 = process(index + 1, count + temp, (k < 0 ? temp2 : speed - temp2)) + 1;
            return min(num1, num2);
        };
        int ans = process(0, 1, speed);
        return ans >= 1000 ? -1 : ans;
    }
};

class Solution1 {
    typedef long long ll;
public:
    int minSkips(vector<int> &dist, int speed, int hoursBefore) {
        if (accumulate(dist.begin(), dist.end(), 0) > (long long) speed * hoursBefore) {
            return -1;
        }
        int n = dist.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        /**
         * @param i 最大可以跳过休息次数
         * @param j 遍历到dist的下标
         * @return 返回一个 dfs(i,j) 的 距离 （这个时间内，speed的距离）
         */
        function<int(int, int)> dfs = [&](int i, int j) {
            if (j < 0) return 0;
            auto &ret = memo[i][j];
            if (ret != -1) return ret;
            ret = (dfs(i, j - 1) + dist[j] + speed - 1) / speed * speed;
            //   int num2 = (dfs(i - 1, j - 1) + dist[j]) / speed * speed;
            if (i) ret = min(ret, (dfs(i - 1, j - 1) + dist[j]));
            return ret;
        };
        for (int i = 0;; ++i) {
            if (dfs(i,n-2)+dist[n-1] <= (ll)speed * hoursBefore){
                return i;
            }
        }
    }
};

//int main() {
//    Solution solution;
//    cout << solution.minSkips({1, 2, 3, 4, 5}, 10000, 1);
//    return 0;
//}