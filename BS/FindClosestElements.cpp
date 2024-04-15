//
// Created by 。 on 2024/3/3.
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

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int> arr, int k, int x) {
        int left = 0, right = arr.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == x) {
                right = mid;
                break;
            } else if (arr[mid] > x) {
                right = mid -1;
            }else{
                left = mid + 1;
            }
        }
        deque<int> returnArr;
        int index = right;
        right = 1,left=0;
        while (k > 0){
            if (index - left >= 0 || index + right < arr.size()){
                if (index - left >= 0 && index + right < arr.size()){
                    int l = abs(arr[index - left] - x);
                    int r = arr[index + right] - x;
                    if (l <= r){
                        returnArr.push_front(arr[index - left]);
                        left ++;
                        k--;
                    }else if (l > r){
                        returnArr.push_back(arr[index + right]);
                        right++;
                        k--;
                    }
                }else if (index - left >= 0){
                    returnArr.push_front(arr[index - left]);
                    left ++;
                    k--;
                } else{
                    returnArr.push_back(arr[index + right]);
                    right++;
                    k--;
                }
            }
        }

        return vector<int>(returnArr.begin(),returnArr.end());
    }
};

//int main() {
//    Solution solution;
//    vector<int> elements = solution.findClosestElements({1, 2, 3, 4, 5}, 4, 3);
//    for (int i = 0; i < elements.size(); ++i) {
//        cout << elements[i] << " ";
//    }
//    return 0;
//}