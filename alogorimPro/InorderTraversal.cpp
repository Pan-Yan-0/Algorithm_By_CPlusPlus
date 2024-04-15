//
// Created by 。 on 2024/4/10.
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
    vector<int> arr;
    void process(TreeNode *node){
        if (node == NULL) return;
        process(node->left);
        arr.push_back(node->val);
        process(node->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        process(root);
        return arr;
    }
};