//
// Created by 。 on 2024/2/2.
//
/**
Definition for a binary tree node.*/
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
    unordered_map<TreeNode *, int> f, g;

    int jump(TreeNode *root) {
        if (!root) return 0;
        return Process(root->left) + Process(root->right);
    }

    int Process(TreeNode *root) {
        if (!root) return 0;
        int val1 = Process(root->left) + Process(root->right);
        int val2 = root->val + jump(root->left) + jump(root->right);
        return val2 > val1 ? val2 : val1;
    }

    int dp(TreeNode *root) {
        if (root == nullptr) return 0;
        dp(root->left);
        dp(root->right);
        f[root] = root->val + g[root->left] + g[root->right];
        g[root] = max(f[root->left],g[root->left]) + max(f[root->right],g[root->right]);
    }

    int rob(TreeNode *root) {
        if (root == nullptr) return 0;
        return max(f[root], g[root]);
    }


};

//int main() {
//    Solution solution;
//
//    return 0;
//}