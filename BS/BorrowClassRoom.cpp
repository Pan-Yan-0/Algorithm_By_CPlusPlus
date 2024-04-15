//#include <vector>
//#include <unordered_map>
//#include <cmath>
//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <deque>
//#include <map>
//#include <cstdio>
//#include <queue>
//#include <climits>
//#include <iostream>
//#include <cstring>
//#include <algorithm>
//
///*
// * 本轮算法是使用二分查找具体哪个订单数是第一个需要修改的订单
// * 在二分查找中判断订单是否是修改订单来对二分区间压缩
// * 判断订单是否是修改订单使用 “差分算法 ” 进行加速
// * 差分建议去看一下（实际上就是前缀和的逆运算）
// * 这里简略的说一下
// * 差分就是（这里是一维的）：有一个数组arr
// * 差分数组为 Differential[i] = arr[i] - arr[i-1]
// * 之后原数组的 arr[i] = sum(Differential[0] ~ Differential[i])(伪代码)
// * */
//using namespace std;
//int n, m;
//const int N = 1000010;
//int lessClassRoom[N]; // 每天剩余的教师数量
//int start[N];//订单 i 借教室的起始日期
//int endDay[N];// 订单 i 借教室的结束日期
//int rooms[N];// 订单 i 借教师的数量
//long long Differential[N];
//class Solution {
//public:
//    // 二分判断条件函数
//    // 使用差分算法进行加速
//    bool check(int mid) {
//        // 本处是用差分计算 ，该天需要的教室数量
//        // 这后面一直说的原数组就是该天需要的教室数量
//        memset(Differential, 0, sizeof Differential);//差分数组
//        for (int i = 1; i <= mid; ++i) {
//            // 差分数组 Differential[i] 加上或者减去 都会影响 i 之后原数组的值
//            // 这里的这个订单从 start[i] 这天开始借 rooms[i] 间教室
//            // 故利用差分数组的性质，start[i]~endDay[i]这几天都会借用 rooms[i]间教室
//            // 故在 Differential[start[i]] 加上 rooms[i]
//            // 即可得到下面的语句
//            Differential[start[i]] += rooms[i];
//            // 因为 endDay[i] + 1 开始这个订单就不用借教室了
//            // 但是上边 Differential[start[i]] += rooms[i];
//            // 会导致原数组[start[i]]后边所有加 rooms[i]
//            // 但是endDay[i] + 1 开始这个订单就不用借教室了
//            // 所以说 前边加上了 后边的减去 就等于没有改变
//            Differential[endDay[i] + 1] -= rooms[i];
//        }
//        // 所谓的原数组 ，每天应该提供教室才能满足订单
//        // 还原原数组并且查看哪天出问题，超过当天剩余的教室
//        for (int i = 1; i <= n; ++i) {
//            // 还原原数组
//            Differential[i] = Differential[i- 1] + Differential[i];
//            if (Differential[i] > lessClassRoom[i]) {
//                return false;
//            }
//        }
//        return true;
//    }
//
//    int brorrowClassRoom() {
//        int left = 0, right = m;
//        while (left < right) {
//            int mid = (left + right + 1)>>1;
//            if (check(mid)) {
//                left = mid;
//            } else {
//                right = mid - 1;
//            }
//        }
//        return right;
//    }
//};
//
////int main() {
////    Solution solution;
////    cin >> n >> m;
////    for (int i = 1; i <= n; ++i) {
////        scanf("%d", &lessClassRoom[i]);
////    }
////    for (int i = 1; i <= m; ++i) {
////        scanf("%d%d%d", &rooms[i], &start[i], &endDay[i]);
////    }
////    int room = solution.brorrowClassRoom();
////    if (room == m) {
////        cout <<0;
////        return 0;
////    } else {
////        cout << -1 << endl << room + 1;
////    }
////    return 0;
////}