////
//// Created by 。 on 2024/3/2.
////
//
//#include <vector>
//#include <unordered_map>
//#include <cmath>
//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <deque>
//#include <map>
//#include <cstdio>
//
//using namespace std;
//
//
//
//class Solution {
//public:
//    long long gapproblem(vector<pair<int, int>> arr) {
//        vector<long long> countArr(len + 1, INT32_MAX);
//        for (int i = 0; i < arr.size(); ++i) {
//            for (int j = 1; j < len + 1; ++j) {
//                long long temp = abs(arr[i].first - j) + arr[i].second;
//                countArr[j] = min(countArr[j], temp);
//            }
//        }
//        long long maxReturn = INT32_MIN;
//        for (int i = 1; i < len + 1; ++i) {
//            maxReturn = max(maxReturn, countArr[i]);
//        }
//        return maxReturn;
//    }
//
//    /*
//     * 本处的check使用在这个时间内，水的流过的所有区间范围
//     * 所有都流过，返回true，否则返回false
//     * */
//    bool check(int mid, vector<pair<int, int>> arr) {
//
//        vector<pair<int, int>> arrLR;//该时间水流过的所有区间数组
//        //先构造出所有区间
//        for (int i = 0; i < n; ++i) {
//            // 判断这个mid时间中这个水阀开了没有，假如没有那就不可能存在区间
//            if (arr[i].second <= mid) {
//                //防止越界
//                int l = arr[i].first - (mid - arr[i].second) >= 1 ? arr[i].first - (mid - arr[i].second) : 1;
//                int r = arr[i].first + (mid - arr[i].second) <= len ? arr[i].first + (mid - arr[i].second) : len;
//                arrLR.push_back(pair<int, int>(l, r));
//            }
//        }
//        /*
//         * 将区间按照first来从小到大排序
//         * */
//        sort(arrLR.begin(), arrLR.end());
//        // 合并所有区间
//        int start = -1, end = -1;//区间包含的管道起始点和末点
//        for (int i = 0; i < arrLR.size(); ++i) {
//            if (arrLR[i].first >= start && arrLR[i].first <= end) {
//                end = max(arrLR[i].second,end);
//            } else{
//                start = arrLR[i].first;
//                end = arrLR[i].second;
//            }
//        }
//
//        return start == 1 && end == len;
//    }
//
//    long long BSProblem(vector<pair<int, int>> arr) {
//        /*
//         * 定义二分区间
//         * 先行预测一遍答案的最大值，这个可以看着用例规模自行计算
//         * 大一些无所谓
//         */
//        int left = 0, right = 2e9;
//        while (left < right) {
//            /*
//             * 此处的mid有些人喜欢直接(left+right)/2
//             * 这种有可能在left+right时就已经超出int的范围，故使用一点数学技巧解决
//             * */
//            int mid = left + (right - left) / 2;
//            if (check(mid, arr)) {
//                right = mid;
//            } else {
//                left = mid + 1;
//            }
//        }
//    }
//};
//
////int main() {
////    Solution solution;
////    cin >> n >> len;
////    vector<pair<int, int>> arr;
////    for (int i = 0; i < n; ++i) {
////        int l, s;
////        cin >> l >> s;
////        arr.push_back(pair<int, int>(l, s));
////    }
//////    sort(arr.begin(), arr.end(), [](pair<int, int> a, pair<int, int> b) {
//////        return a.first < b.first;
//////    });
////    cout << solution.BSProblem(arr);
////    return 0;
////}
