/*
 * @lc app=leetcode.cn id=559 lang=cpp
 *
 * [559] N叉树的最大深度
 */
#include "main.h"
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
  public:
    // int maxDepth(Node *root) {
    //     if (root == nullptr)
    //         return 0;
    //     int res = 0;
    //     queue<Node *> q;
    //     q.push(root);
    //     while (!q.empty()) {
    //         ++res;
    //         int size = q.size();
    //         while (size--) {
    //             auto t = q.front();
    //             q.pop();
    //             for (auto child : t->children)
    //                 if (child)
    //                     q.push(child);
    //         }
    //     }
    //     return res;
    // }

    int maxDepth(Node *root) {
        if (root == nullptr)
            return 0;
        int res = 0;
        dfs(root, 1, res);
        return res;
    }

    void dfs(Node *root, int level, int &res) {
        if (root == nullptr)
            return;
        res = max(res, level);
        for (auto child : root->children)
            dfs(child, level + 1, res);
    }
};
// @lc code=end
