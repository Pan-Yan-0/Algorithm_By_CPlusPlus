//
// Created by 。 on 2024/4/24.
//
#include "../theInclude.h"

class Solution1 {
public:
    int amountOfTime(TreeNode *root, int start) {
        TreeNode *startNode;
        bool find = false;
        int ans = 0;
        unordered_map<TreeNode *, vector<TreeNode *>> unorderedMap;
        queue<TreeNode *> qq;
        qq.push(root);
        while (!qq.empty()) {
            TreeNode *pNode = qq.front();
            if (pNode->val == start) {
                startNode = pNode;
            }
            qq.pop();
            if (pNode == NULL)continue;

            if (pNode->left != NULL) {
                qq.push(pNode->left);
                unorderedMap[pNode].push_back(pNode->left);
                unorderedMap[pNode->left].push_back(pNode);
            }
            if (pNode->right != NULL) {
                qq.push(pNode->right);
                unorderedMap[pNode].push_back(pNode->right);
                unorderedMap[pNode->right].push_back(pNode);
            }
        }
        unordered_map<TreeNode *, bool> mark;
        function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int {
            if (mark[node]) {
                return 0;
            }
            mark[node] = true;
            int ret = 0;
            for (int i = 0; i < unorderedMap[node].size(); ++i) {
                int temp = dfs(unorderedMap[node][i]);
                ret = max(ret, temp);
            }
            return ret + 1;
        };
        for (int i = 0; i < unorderedMap[startNode].size(); ++i) {
            int temp = dfs(unorderedMap[startNode][i]);
            ans = max(ans, temp);
        }
        return ans;
    }
};

class Solution2 {
public:
    int amountOfTime(TreeNode *root, int start) {
        // root的左右两边的最大深度
        // 假设在一颗子树中找到start，那么这个子树就返回这个子树到start的距离，并且使用变量来存储start子树的最大深度
        // 存储start子树的父节点的最远距离
        int sonDeth = 0;

        function<int(TreeNode *)> dfs = [&](TreeNode *node) -> int {
            if (node->val == start) {
                queue<pair<TreeNode *, int>> qq;
                qq.push({node, 0});
                int deph = 0;
                while (!qq.empty()) {
                    auto [front, dept] = qq.front();
                    deph = max(deph, dept);
                    if (front->left != NULL) {
                        qq.push({front->left, dept + 1});
                    }
                    if (front->right != NULL) {
                        qq.push({front->right, dept + 1});
                    }

                }
                sonDeth = deph;
                return 0;
            }
        };
    }
};

class Solution {
    int ans = 0, start;
    pair<int, bool> dfs(TreeNode *node) {
        if (node == nullptr) {
            return {0, false};
        }
        auto [l_len, l_found] = dfs(node->left);
        auto [r_len, r_found] = dfs(node->right);
        // 回溯后就开始遍历，
        if (node->val == start) {
            // 计算子树 start 的最大深度
            // 注意这里和方法一的区别，max 后面没有 +1，所以算出的也是最大深度
            ans = max(l_len, r_len);
            return {1, true}; // 找到了 start
        }
        // 这个startNode的左右子树遍历直接跳出
        if (l_found || r_found) {
            // 只有在左子树或右子树包含 start 时，才能更新答案
            ans = max(ans, l_len + r_len); // 两条链拼成直径
            // 保证 start 是直径端点
            // 树的直径距离
            return {(l_found ? l_len : r_len) + 1, true};
        }
        // 假如不是就不更新，仅仅放回最深的子树长度
        return {max(l_len, r_len) + 1, false};
    }
public:
    int amountOfTime(TreeNode *root, int start) {
        this->start = start;
        dfs(root);
        return ans;
    }
};
