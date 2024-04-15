#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1,0);
        dp[1] = 1;
        dp[2] = 2;
        for (int i = 3; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                if (j-1==0||i-j==0){
                    dp[i]+=dp[j-1]+dp[i-j];
                    continue;
                }
                dp[i] += dp[j-1] * dp[i-j];
            }
        }
        return dp[n];
    }
};
//int main(){
//    Solution s;
//    cout << s.numTrees(3);
//    return 0;
//}
