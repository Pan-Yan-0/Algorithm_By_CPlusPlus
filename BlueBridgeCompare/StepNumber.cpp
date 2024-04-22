////
//// Created by 。 on 2024/4/20.
////
//#include <vector>
//#include <unordered_map>
//#include <cmath>
//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <deque>
//#include <map>
//#include <queue>
//#include <cstring>
//#include <algorithm>
//#include <list>
//#include <stack>
//#include <climits>
//#include <numeric>
//
//using namespace std;
//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <functional>
//
//using namespace std;
//
//const int xI[8] = {0, 1, 1, 1, 0, -1, -1, -1};
//const int yI[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
//int ban[11][11][11][11] = {0};
//
////int main() {
////    int n, k;
////    cin >> n >> k;
////    vector<vector<int>> matrix(n, vector<int>(n, 0));
////    for (int i = 0; i < n; ++i) {
////        for (int j = 0; j < n; ++j) {
////            cin >> matrix[i][j];
////        }
////    }
////    string ans;
////    vector<vector<bool>> mark(n, vector<bool>(n, false));
////
////    bool find = false;
////    function<void(int, int, int)> dfs = [&](int x, int y, int need) {
////        if (find) return;
////        if (x == n - 1 && y == n - 1) {
////            if (ans.size() == n * n) {
////                find = true;
////                return;
////            }
////        }
////        if (ans.size() == n * n) {
////            cout << ans << endl;
////            ans.pop_back();
////            return;
////        }
////        for (int i = 0; i < 8; ++i) {
////            int xN = xI[i] + x, yN = yI[i] + y;
////            if (xN < 0 || xN >= n || yN < 0 || yN >= n || mark[yN][xN] || matrix[yN][xN] != need) continue;
////            if (i % 2 == 1) {
////                if (ban[x][yN][xN][y] == 1 || ban[xN][y][x][yN] == 1) continue;
////                else {
////                    ban[x][y][xN][yN] = 1;
////                }
////            }
////            ans.push_back(i + '0');
////            mark[yN][xN] = true;
////            dfs(xN, yN, (need + 1) % k);
////            if (find) return;
////            // Remove from queue if it's a diagonal move
////            if (i % 2 == 1) {
////                ban[x][y][xN][yN] = 0;
////            }
////        }
////        ans.pop_back();
////        mark[y][x] = false;
////    };
////
////    ans.push_back('0');
////    mark[0][0] = true;
////    dfs(0, 0, 1);
////    if (ans.empty()) cout << "-1";
////    else cout << ans;
////    return 0;
////}
