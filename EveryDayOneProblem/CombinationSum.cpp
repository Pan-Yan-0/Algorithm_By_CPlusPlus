
//
// Created by 。 on 2024/4/20.
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
#include <stack>
#include <climits>
#include <numeric>

using namespace std;

class Solution1 {
public:
    vector<vector<int>> combinationSum(vector<int> candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ansTemp;

        function<void(int, vector<int>)> process = [&](int target, vector<int> arr) {
            if (target < 0) return;
            if (target == 0) {
                ansTemp.push_back(arr);
            }
            for (int i = 0; i < candidates.size(); ++i) {
                vector<int> temp(arr);
                temp[i]++;
                process(target - candidates[i], temp);
            }
        };
        process(target, vector<int>(candidates.size(), 0));
        vector<vector<int>> ans;
        for (int i = 0; i < ansTemp.size(); ++i) {
            vector<int> temp;
            for (int j = 0; j < ansTemp[i].size(); ++j) {
                while (ansTemp[i][j]) {
                    temp.push_back(candidates[j]);
                    ansTemp[i][j]--;
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

class Solution2 {
public:
    vector<vector<int>> combinationSum(vector<int> candidates, int target) {
        sort(candidates.begin(), candidates.end());
        function<vector<vector<int>>(int, int)> process = [&](int index, int target) {
            if (index >= candidates.size()) return vector<vector<int>>();
            if (target == 0) {
                return vector<vector<int>>{{}};
            }
            if (target < 0) {
                return vector<vector<int>>();
            }
            vector<vector<int>> ret;
            for (int i = 0; i <= target / candidates[index]; ++i) {
                vector<vector<int>> temp = process(index + 1, target - candidates[index] * i);
                if (temp.size() == 0) return vector<vector<int>>();
                for (int j = 0; j < i; ++j) {
                    for (int k = 0; k < temp.size(); ++k) {
                        for (int l = 0; l < i; ++l) {
                            temp[k].push_back(candidates[index]);
                        }
                        ret.push_back(temp[k]);
                    }

                }
            }
            return ret;
        };
        return process(0, target);
    }
};

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ansTemp;
        function<void(int, int, vector<int>)> dfs = [&](int index, int target, vector<int> arr) {
            if (target == 0) {
                return ansTemp.push_back(arr);
            }
            if (index >= candidates.size()) return;
            for (int i = 0; i <= target / candidates[index]; ++i) {
                vector<int> temp(arr);
                for (int j = 0; j < i; ++j) {
                    temp.push_back(candidates[index]);
                }
                dfs(index + 1, target - candidates[index] * i, temp);
            }
        };
        return ansTemp;
    }
};

//int main() {
//    Solution solution;
//    auto arr = solution.combinationSum({2, 3, 6, 7}, 7);
//    return 0;
//}