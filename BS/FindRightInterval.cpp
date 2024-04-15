//
// Created by 。 on 2024/2/27.
//
//#include"bits/stdc++.h"
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <deque>
#include <map>

using namespace std;
//class Solution {
//public:
//    vector<int> findRightInterval(vector<vector<int>>& intervals) {
//        vector<pair<int,int>>sI;
//        vector<pair<int,int>>eI;
//        int n=intervals.size();
//        for(int i=0;i<n;i++)
//        {
//            sI.emplace_back(intervals[i][0],i);
//            eI.emplace_back(intervals[i][1],i);
//        }
//        sort(sI.begin(),sI.end());
//        sort(eI.begin(),eI.end());
//
//        vector<int> ans(n,-1);
//        for(int i=0,j=0;i<n&&j<n;i++)
//        {
//            while(j<n && eI[i].first>sI[j].first)
//            {
//                j++;
//            }
//            if(j<n)
//            {
//                ans[eI[i].second]=sI[j].second;
//            }
//        }
//        return ans;
//    }
//};
class Solution {
public:
    vector<int> process(vector<vector<int>> &arr) {
        vector<int> returnArr(arr.size(), -1);
        vector<int> minMark(arr.size(), 400000);
        for (int i = 0; i < arr.size(); ++i) {
            for (int j = 0; j < arr.size(); ++j) {
                if (arr[i][1] <= arr[j][0]) {
                    if (returnArr[i] == -1) {
                        returnArr[i] = j;
                        minMark[i] = arr[j][0];
                    } else {
                        if (minMark[i] > arr[j][0]) {
                            returnArr[i] = j;
                            minMark[i] = arr[j][0];
                        }
                    }
                }
            }
        }
        return returnArr;
    }

    vector<int> BS(vector<vector<int>> arr) {
        map<int, int> map;
        for (int i = 0; i < arr.size(); ++i) {
            map.insert(pair<int, int>(arr[i][0], i));
        }
        sort(arr.begin(), arr.end(), [](auto a, auto b) {
            return a[0] < b[0];
        });
        vector<int> returnArr(arr.size(), -1);
        vector<int> minArr(arr.size(), INT32_MAX);
        for (int i = 0; i < arr.size(); ++i) {
            int left = 0, right = arr.size() - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (arr[mid][0] == arr[i][1]) {
                    auto iterator1 = map.find(arr[mid][0]);
                    auto iterator2 = map.find(arr[i][0]);
                    returnArr[iterator2->second] = iterator1->second;
                    break;
                } else if (arr[mid][0] > arr[i][1]) {
                    auto iterator1 = map.find(arr[mid][0]);
                    auto iterator2 = map.find(arr[i][0]);


                    if (minArr[iterator2->second] > arr[mid][0]) {
                        minArr[iterator2->second] = arr[mid][0];
                        returnArr[iterator2->second] = iterator1->second;
                    }
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        return returnArr;
    }
    vector<int> DoublePoint(vector<vector<int>> intervals){
        vector<pair<int,int>> FI;
        vector<pair<int,int>> SI;
        unsigned long size1 = intervals.size();
        for (int i = 0; i < size1; ++i) {
            FI.push_back(pair(intervals[i][0],i));
            SI.push_back(pair(intervals[i][1],i));
        }
        sort(FI.begin(),FI.end());
        sort(SI.begin(),SI.end());
        vector<int> returnArr(size1,-1);
        for (int i = 0,j = 0; i < size1 && j < size1; ++i) {
            while (j < size1 && SI[i].first > FI[j].first){
                j++;
            }
            if (j<size1){
                returnArr[SI[i].second] =  FI[j].second;
            }
        }
        return returnArr;


    }
    vector<int> findRightInterval(vector<vector<int>> intervals) {
        return DoublePoint(intervals);
    }
};

//int main() {
//    Solution s;
//    //[3,4],[2,3],[1,2]
//    //[[1,12],[2,9],[3,10],[13,14],[15,16],[16,17]]
//    const vector<int> &interval = s.findRightInterval({{1,  12},
//                                                       {2,  9},
//                                                       {3,  10},
//                                                       {13, 14},
//                                                       {15, 16},
//                                                       {16, 17}});
//    for (int i = 0; i < interval.size(); ++i) {
//        cout << interval[i] << " ";
//    }
//    cout << endl;
//    return 0;
//}
