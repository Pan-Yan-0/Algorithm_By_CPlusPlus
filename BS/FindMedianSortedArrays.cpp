
#include <vector>
#include <unordered_map>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <deque>
#include <map>
#include <cstdio>

using namespace std;

class Solution {
public:
    /*
     * 本题使用二分查找来找到分隔两个数组的分割线
     * 这个分割线左右两边的数组个数满足于：
     * 左边的元素个数等于右边的元素个数（此时是两个数组的大小和为偶数）
     * 或者是左边的元素个数等于右边的元素个数（此时是两个数组的大小和为奇数）
     * 数学原理为：分隔先的左边所有值都永远小于右边的所有值
     * 这样分割的话就会让中位数在分割线的两边（可以动手画一下，编辑器没这个功能，不帮大家画了）
     * 竖杠为分隔线分割线的右边最小值必定比左边最大值还要大（max(3,4) < min(5,6)）
     * 1    3 |  5   7 (这里的分隔线位置是2)
     * 2    3   4 |  6   10(这里的分隔线位置是3)
     * */
    double BSSolution(vector<int> nums1, vector<int> nums2) {

        //使得nums1的大小永远小于或者等于nums2的大小
        if (nums1.size() > nums2.size()) {
            vector<int> temp(nums1);
            nums1 = nums2;
            nums2 = temp;
        }
        /*
         * leftTotalNum为左边的元素有几个
         * 且规定左边的元素必定比右边的元素多一个或者等于
         * 此处使用 +1来满足上述规定
         * 此处的(nums1.size() + nums2.size() + 1)有可能会整形溢出
         * 可以替换成nums1.size() + (nums2.size() - nums1.size() + 1) / 2
         * 假如测试用例连替换之后都溢出的话，那得换long long了
         * */
        int leftTotalNum = (nums1.size() + nums2.size() + 1) / 2;
        /**
         * 定义left，right区间
         * 这里二分nums1，nums2都行
         * 因为找到nums1在哪里分割就可以通过leftTotalNum找到nums2的分割
         * 本处二分nums1
         */
        int left = 0, right = nums1.size();//right没有必要减一，因为这个是二分分隔线的位置
        //left < right当while结束之后，得到left = right的局面
        while (left < right) {
            /*
             * 1    3 |  5   7 (这里的分隔线位置是2)
             *| 2    3   4   6   10(这里的分隔线位置是0)
             * */
            /*
             * nums1的假设分隔线位置
             * 为何不加一：防止后边的 right = mid 死循环
             * */
            int mid = left + (right - left) / 2;
            int r = leftTotalNum - mid;// nums2的分隔线位置通过nums1的分割线位置计算出来
            /*
             * 根据刚刚开头的：数学原理为：分隔线的左边所有值都永远小于右边的所有值
             * 而且nums1和nums2都是升序，只需要判断(nums1[mid] >= nums2[r - 1] && nums2[r] >= nums1[mid - 1])是否满足
             * 假如有一个不满足就要调整left或者right
             * 此处会存在越界问题，本人没有什么好方法，还可以写一个check()函数判断是否满足条件（不写出来了）
             * 越界问题是因为分隔线在数组最左或者最右，按照人为大量模拟之后这样写是没有问题
             * 个人理解是nums1[mid] < nums2[r - 1]有可能越界就是r = 0,即mid = leftTotalNum
             * 全部都在nums1去选择，本处因为一开始就搞出（nums1.size() <= nums2.size()）
             * 全部选择nums1的话只有（nums1.size() == nums2.size()）
             * 此时nums1全部都在分割线的左边，也说明了此时是（left == right），因为mid == nums1.size()
             * 此时已经跳出循环，不可能发生，各位看到这里的可以尝试一下
             * 我就举出一个例子：假如真正的分割线在这里（下图）根据二分过程（while循环里）是不可能循环一次
             * 此时nums1全部都在分割线的左边，也说明了此时是（left == right），因为mid == nums1.size()
             * 到这个情况就跳出while了
             * 1    2   3   4 |
             *|5    6   7   8
             *
             * 使用另一个的话各位可以自行思考一下也是类似
             * */
            if (nums1[mid] < nums2[r - 1]) {
                left = mid + 1;
            } else {
                // (nums1[mid] >= nums2[r - 1])满足这个还得继续要缩小
                // 因为这个 （nums2[r] >= nums1[mid - 1]）不一定满足
                right = mid;
            }

        }
        // 上述最难的地方结束之后
        // 已经找到nums1分隔线的位置，并且此时的left == right
        int arr1 = left; // nums1分隔线的位置
        int arr2 = leftTotalNum - arr1;// nums2的分隔线位置通过nums1的分割线位置计算出来
        // 此时找中位数，先把分割线两旁的4个数给拎出来
        // 此时还会有越界问题
        // 这里的越界问题，两个分隔线都有可能发生，一般来说nums2不会，但当nums1.size == nums2.size，就有可能了
        // 因为后面找分隔线左边是最大值，分隔线右边是最小值，故越界就给一个不要破坏判断的值即可
        int nums1Left = arr1 - 1 < 0 ? INT32_MIN : nums1[arr1 - 1];
        int nums1Right = arr1 == nums1.size() ? INT32_MAX : nums1[arr1];
        int nums2Left = arr2 - 1 < 0 ? INT32_MIN : nums2[arr2 - 1];
        int nums2Right = arr2  == nums2.size() ? INT32_MAX : nums2[arr2];
        /*
         * 先判断中位数得找几个数
         * 两个数组之和为奇数找一个，即分割线左边的最大值
         * 为偶数得找两个，即分割线左边的最大值和分割线右边的最小值
         * */
        // 直接全算了先
        int leftMaxNum = nums1Left > nums2Left ? nums1Left : nums2Left;
        int rightMinNum = nums1Right > nums2Right ? nums2Right : nums1Right;
        if ((nums1.size() + nums2.size()) % 2 == 1){
            // 奇数
            return (double)leftMaxNum;
        } else{
            return ((double )leftMaxNum + (double )rightMinNum) / 2;
        }

    }

    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        return BSSolution(nums1, nums2);
    }

    // 第一次想到的写法，不解释了
    double ViolentSolution(const vector<int> &nums1, const vector<int> &nums2) const {
        int l = 0, r = 0;
        int sum = nums1.size() + nums2.size();
        if (sum == 1) {
            return nums1.empty() ? nums2[0] : nums1[0];
        }
        int mid = sum / 2;
        int maxIndex = 0;
        int leftNum, rightNum;
        bool leftADD = true;
        while (l < nums1.size() || r < nums2.size()) {
            if (l < nums1.size() && r < nums2.size()) {
                if (nums1[l] > nums2[r]) {
                    r++;
                    leftADD = false;
                } else {
                    l++;
                    leftADD = true;
                }
            } else if (l < nums1.size()) {
                l++;
                leftADD = true;
            } else {
                r++;
                leftADD = false;
            }
            maxIndex++;
            if (maxIndex == mid) {
                if (leftADD) {
                    leftNum = nums1[l - 1];
                } else {
                    leftNum = nums2[r - 1];
                }
            }
            if (maxIndex == mid + 1) {
                if (leftADD) {
                    rightNum = nums1[l - 1];
                } else {
                    rightNum = nums2[r - 1];
                }
                if (sum % 2 == 0) {
                    return ((double) leftNum + (double) rightNum) / 2;
                } else {
                    return (double) rightNum;
                }
            }
        }
        /*不可能到达*/
        return 0;
    }
};

//int main() {
//    Solution solution;
//    cout << solution.findMedianSortedArrays({}, {0});
//    return 0;
//}