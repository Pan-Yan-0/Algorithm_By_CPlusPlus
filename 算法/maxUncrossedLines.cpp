//
// Created by 。 on 2023/9/19.
//

#include "maxUncrossedLines.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
    int process(vector<int> nums1,vector<int> nums2){
        int length1 = nums1.size();
        int length2 = nums2.size();

    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        return process(nums1,nums2);
    }
};

int main(){
    Solution s;
    vector<int> num1 = {2,5,1,2,5};
    vector<int> num2 = {10,5,2,1,5,2};
    cout << s.maxUncrossedLines(num1,num2);
    return 0;
}