//
// Created by 。 on 2024/6/8.
//
#include "../theInclude.h"
using namespace std;
class Solution {
public:
    int maximumLength(std::vector<int> nums, int k) {
        int n = nums.size();
        int left = 0, right = 0;
        int maxLen = 0;
        int changes = 0;
        if (k == 0) {
            unordered_map<int, int> unorderedMap;
            for (int i = 0; i < nums.size(); ++i) {
                unorderedMap[nums[i]] += 1;
            }
            int ret = 0;
            for (const auto &item: unorderedMap){
                ret = max(item.second,ret);
            }
            return ret;
        }
        while (right < n) {
            if (right > 0 && nums[right] != nums[right - 1]) {
                ++changes;
            }

            while (changes > k) {
                if (nums[left] != nums[left + 1]) {
                    --changes;
                }
                ++left;
            }

            maxLen = std::max(maxLen, right - left + 1);
            ++right;
        }

        return maxLen;
    }
};
int main(){
    Solution solution;
    cout << solution.maximumLength({1,2,3,4,5,1},0);
    return 0;
}
