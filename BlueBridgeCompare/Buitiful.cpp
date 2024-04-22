////
//// Created by 。 on 2024/4/20.
////
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <functional>
//
//using namespace std;
//
//// 定义宝石结构体，包含宝石值和索引
//struct Gem {
//    int value;
//    int index;
//};
//
//// 自定义比较函数，用于最小堆
//struct CompareGem {
//    bool operator()(const Gem& g1, const Gem& g2) {
//        return g1.value > g2.value;
//    }
//};
//
//// 计算最大公约数
//int gcd(int a, int b) {
//    if (b == 0) return a;
//    return gcd(b, a % b);
//}
//
//// 计算最小公倍数
//int lcm(int a, int b) {
//    return a * b / gcd(a, b);
//}
//
////int main() {
////    int N;
////    cin >> N;
////    vector<int> gems(N);
////    for (int i = 0; i < N; ++i) {
////        cin >> gems[i];
////    }
////
////    // 使用优先队列实现最小堆
////    priority_queue<Gem, vector<Gem>, CompareGem> pq;
////
////    // 将所有由第一个宝石与其余宝石组成的组合放入堆中
////    for (int i = 1; i < N; ++i) {
////        pq.push({gems[0] * gems[i] / gcd(gems[0], gems[i]), i});
////    }
////
////    // 处理足够数量的组合
////    for (int count = 0; count < N - 2; ++count) {
////        // 取出当前最小的组合
////        Gem min_gem = pq.top();
////        pq.pop();
////
////        // 将最小组合与下一个宝石组合并加入堆中
////        int next_index = min_gem.index + 1;
////        if (next_index < N) {
////            pq.push({min_gem.value * gems[next_index] / gcd(min_gem.value, gems[next_index]), next_index});
////        }
////    }
////
////    // 取出堆中最小的组合作为结果
////    Gem result = pq.top();
////
////    // 输出结果
////    cout << gems[0] << " " << gems[result.index] << " ";
////    for (int i = result.index + 1; i < N; ++i) {
////        if (i != result.index + 1) cout << " ";
////        cout << gems[i];
////    }
////    cout << endl;
////
////    return 0;
////}
