//
// Created by 。 on 2024/2/3.
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int MaxSum = INT16_MIN;
    int maxGath(TreeNode* node){
        if (!node) return 0;
        int left = max(maxGath(node->left),0);
        int right = max(maxGath(node->right),0);
        int nodeVal = left + right;
        if (MaxSum < nodeVal) MaxSum = nodeVal + node->val;
        return node->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        maxGath(root);
        return MaxSum;
    }
};

//int main(){
//    Solution solution;
//    return 0;
//}