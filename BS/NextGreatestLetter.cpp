//
// Created by 。 on 2024/2/26.
//
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <deque>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char> letters, char target) {
        int left = 0, right = letters.size() - 1;
        while (left <= right) {
            int mid = (left + right) /2;
            if (target == letters[mid]) left = mid;
            if (target < letters[mid]) right = mid - 1;
            else {
                left = mid + 1;
            }
        }
        if (left >= letters.size()) return letters[0];
        else return letters[left];
    }
};

//int main() {
//    Solution solution;
//    cout << solution.nextGreatestLetter({'e', 'e', 'g','g'}, 'g');
//    return 0;
//}