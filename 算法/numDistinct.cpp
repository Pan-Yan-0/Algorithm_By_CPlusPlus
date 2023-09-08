//
// Created by 。 on 2023/9/8.
//

#include "numDistinct.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int process(string ori, string str, string tar, int index) {
        if (str.size() == tar.size()) {
            if (str == tar) {
                return 1;
            } else {
                return 0;
            }
        }
        if (index == ori.size()) {
            return 0;
        }
        int num1 = process(ori, str, tar, index + 1);
        string newStr = string(str + ori[index]);
        int num2 = process(ori, newStr, tar, index + 1);
        return num1 + num2;
    }

public:
    int numDistinct(string s, string t) {
        string str;
        return process(s,str,t,0);
    }
};

int main() {
    Solution s;
    cout << s.numDistinct("bccbcdcabadabddbccaddcbabbaaacdba", "bccbbdc") << endl;
    return 0;
}