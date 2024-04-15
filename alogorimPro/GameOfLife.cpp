//
// Created by 。 on 2024/4/9.
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
    vector<pair<int, int>> step = {{1,  0},
                                   {1,  1},
                                   {1,  -1},
                                   {0,  1},
                                   {-1, 1},
                                   {-1, 0},
                                   {-1, -1},
                                   {0,  -1}};
public:
    void gameOfLife(vector<vector<int>> &board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                int now = board[i][j];
                int sum = 0;
                for (int k = 0; k < step.size(); ++k) {
                    int a = step[k].first, b = step[k].second;
                    if (i + a < 0 || i + a >= board.size() || j + b < 0 || j + b >= board.size()) {
                        continue;
                    } else {
                        sum += board[i + a][j + b];
                    }
                }
                if (now == 0){
                    if (sum == 3){
                        board[i][j] += 2;
                    }
                } else{
                    if (sum == 2 || sum == 3){
                        board[i][j] += 2;
                    }
                }
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                board[i][j] = board[i][j] & 2;
            }
        }
    }
};