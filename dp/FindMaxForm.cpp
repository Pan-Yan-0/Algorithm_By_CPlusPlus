////
//// Created by 。 on 2024/2/10.
////
//#include <vector>
//#include <unordered_map>
//#include <cmath>
//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <deque>
//
//using namespace std;
//
//class Solution {
//public:
//
//    int process(vector<pair<int, int>> arr, int k, int m, int n) {
//        if (arr.size() == k) {
//            return 0;
//        }
//        int maxForm = process(arr, k + 1, m, n);
//        if (m - arr[k].first < 0 || n - arr[k].second < 0) {
//            return maxForm;
//        } else {
//            int case1 = process(arr, k + 1, m - arr[k].first, n - arr[k].second) + 1;
//            maxForm = max(case1, maxForm);
//        }
//        return maxForm;
//    }
//
//    int dpProcess(vector<pair<int, int>> arr, int m, int n) {
//        deque<pair<int, int>> fdpless(arr.size() + 1);
//        fdpless[arr.size()].first = m;
//        fdpless[arr.size()].second = n;
//        vector<int> fdp(arr.size() + 1, 0);
//        deque<pair<int, int>> qdpless(arr.size() + 1);
//        qdpless[arr.size()].first = m;
//        qdpless[arr.size()].second = n;
//        vector<int> qdp(arr.size() + 1, 0);
//        for (int i = arr.size() - 1; i >= 0; --i) {
//            if (fdp[i + 1] > qdp[i + 1]) {
//                qdp[i] = fdp[i + 1];
//                qdpless[i] = fdpless[i + 1];
//            } else {
//                qdp[i] = qdp[i + 1];
//                qdpless[i] = qdpless[i + 1];
//            }
//            if (fdp[i + 1] > qdp[i + 1] && fdpless[i + 1].first - arr[i].first >= 0 &&
//                       fdpless[i + 1].second - arr[i].second >= 0) {
//                fdp[i] = fdp[i + 1] + 1;
//                fdpless[i] = fdpless[i + 1];
//                fdpless[i].first -= arr[i].first;
//                fdpless[i].second -= arr[i].second;
//            }
//            else if(fdp[i + 1] < qdp[i + 1]&&
//                    qdpless[i + 1].first - arr[i].first >= 0 &&
//                    qdpless[i + 1].second - arr[i].second >= 0){
//                fdp[i] = qdp[i + 1] + 1;
//                fdpless[i] = qdpless[i + 1];
//                fdpless[i].first -= arr[i].first;
//                fdpless[i].second -= arr[i].second;
//            }else{
//                    fdpless[i] = qdpless[i];
//                    fdp[i] = qdp[i];
//                }
//            }
//        }
//        return max(fdp[0], qdp[0]);
//    }
//
//    int findMaxForm(vector<string> strs, int m, int n) {
//        vector<pair<int, int>> arr;
//        for (int i = 0; i < strs.size(); ++i) {
//            pair<int, int> temp;
//            for (int j = 0; j < strs[i].size(); ++j) {
//                if (strs[i][j] == '0') temp.first++;
//                if (strs[i][j] == '1') temp.second++;
//            }
//            arr.emplace_back(temp);
//        }
////        return dpProcess(arr, m, n);
////        return process(arr, 0, m, n);
//    }
//};
//
////int main() {
////    Solution solution;
////    //cout << solution.findMaxForm({"11111", "100", "1101", "1101", "11000"}, 5, 7);
////    cout << solution.findMaxForm(
////            {"0", "11", "1000", "01", "0", "101", "1", "1", "1", "0", "0", "0", "0", "1", "0"
////             , "0110101", "0", "11","01", "00", "01111", "0011", "1", "1000", "0", "11101"
////             , "1", "0", "10", "0111"}, 9, 80);
////    return 0;
////}