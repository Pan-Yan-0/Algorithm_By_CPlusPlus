////
//// Created by 。 on 2024/5/30.
////
//#include "../theInclude.h"
//class Solution {
//public:
//    int maximumLength(string s) {
//
//        int n = s.size();
//        unordered_map<char,vector<int>> mapStr;
//        int l = 0, r = 0;
//        while (r < s.size()) {
//            if (s[l] == s[r]) {
//                r++;
//            } else {
//                for (int i = 1; i <= r - l; ++i) {
//                    mapStr[s[l]]
//                    mapStr[s.substr(l, i)] += r - l + 1 - i;
//                }
//                l = r;
//            }
//        }
//        for (int i = 1; i <= r - l; ++i) {
//            mapStr[s.substr(l, i)] += r - l + 1 - i;
//        }
//        int ret = -1;
//        for (auto map_str: mapStr) {
//            if (map_str.second >= 3) {
//                int b = (int)map_str.first.size();
//                ret = max(ret, b);
//            }
//        }
//        return ret;
//    }
//};
