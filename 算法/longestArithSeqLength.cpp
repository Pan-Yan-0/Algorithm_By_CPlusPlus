//
// Created by 。 on 2023/9/11.
//

#include "longestArithSeqLength.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    int method(vector<int> nums){

    }
public:
    int longestArithSeqLength(vector<int>& nums) {
        return method(nums);
    }
};

int main(){
    //20,1,15,3,10,5,8
    Solution s;
    vector<int> num;
    num.push_back(20);
    num.push_back(1);
    num.push_back(15);
    num.push_back(3);
    num.push_back(10);
    num.push_back(5);
    num.push_back(8);
    cout << s.longestArithSeqLength(num);
    return 0;
}