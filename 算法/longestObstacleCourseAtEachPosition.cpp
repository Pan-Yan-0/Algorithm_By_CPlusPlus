//
// Created by 。 on 2023/9/15.
//

#include "longestObstacleCourseAtEachPosition.h"
#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

class Solution {
    //1,1,2,2,2,3,4,5,4,6,6,2,3,7,7,8,5
private:
    int findNum(vector<int> nums, int number, int index) {
        for (int i = index - 1; i >= 0; --i) {
            if (nums[i] <= number) {
                return i;
            }
        }
        return -1;
    }

    vector<int> DP(vector<int> nums) {
        int length = nums.size();
        vector<int> dp(length, 1);
        for (int i = 1; i < length; ++i) {
            int index = findNum(nums, nums[i], i);
            if (index == -1) {
            } else {
                dp[i] = dp[index] + 1;
            }
        }
        return dp;
    }

    vector<int> DP1(vector<int> nums) {
        int length = nums.size();
        vector<int> dp(length, 1);
        for (int i = 1; i < length; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] >= nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        return dp;
    }
    vector<int> greedy(vector<int> obstacles){
        vector<int> d, ans;
        for (int ob: obstacles) {
            // 这里需要改成 >=
            if (d.empty() || ob >= d.back()) {
                d.push_back(ob);
                ans.push_back(d.size());
            }
            else {
                // 将 300 题解中的二分查找改为 API 调用使得代码更加直观
                // 如果是最长严格递增子序列，这里是 lower_bound
                // 如果是最长递增子序列，这里是 upper_bound
                int loc = upper_bound(d.begin(), d.end(), ob) - d.begin();
                ans.push_back(loc + 1);
                d[loc] = ob;
            }
        }
        return ans;
    }
    
    
    vector<int> greedy1(vector<int> nums){
        int length = nums.size();
        vector<int> dp;
        vector<int> answer(length,1);
        dp.push_back(nums[0]);
        for (int i = 1; i < length; ++i) {
            auto iterator = upper_bound(dp.begin(), dp.end(), nums[i]);
            if (iterator == dp.end()){
                dp.push_back(nums[i]);
                answer[i] = dp.size();
            } else {
                int index = iterator - dp.begin();
                answer[i] = index + 1;

                dp[index] = nums[i];
            }
        }
        return answer;
    }
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int> &obstacles) {
        return greedy1(obstacles);
    }
};

//int main() {
//
//    Solution s;
//    vector<int> nums;
//    //201,19,363,292,123,211,333,387,296,500,401,42,176,476,473,498
//    nums.push_back(201);
//    nums.push_back(19);
//    nums.push_back(363);
//    nums.push_back(292);
//    nums.push_back(123);
//    nums.push_back(211);
//    nums.push_back(333);
//    nums.push_back(387);
//    nums.push_back(296);
//    nums.push_back(500);
//    nums.push_back(401);
//    nums.push_back(42);
//    nums.push_back(176);
//    nums.push_back(476);
//    nums.push_back(473);
//    nums.push_back(498);
//    for (const auto &item: s.longestObstacleCourseAtEachPosition(nums)) {
//        cout << item << " ";
//    }
//    cout << endl;
//
//    return 0;
//}