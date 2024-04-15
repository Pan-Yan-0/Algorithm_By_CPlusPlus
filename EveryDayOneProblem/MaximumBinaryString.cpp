//
// Created by 。 on 2024/4/10.
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

using namespace std;

class Solution {
public:
    string maximumBinaryString(string binary) {
        if (binary.size() == 1) return binary;
        int left = 0, right = 1;
        while (right < binary.size()) {
            if (binary[left] == '0' && binary[right] == '0') {
                binary[left] = '1';
                swap(binary[left+1],binary[right]);
                left++;right++;
            } else{
                if (binary[left] == '1'){
                    left++;
                    if (left == right){
                        right++;
                    }
                }
                if (binary[right] == '1'){
                    right++;
                }
            }
        }
        return binary;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.maximumBinaryString("000110");
//    return 0;
//}