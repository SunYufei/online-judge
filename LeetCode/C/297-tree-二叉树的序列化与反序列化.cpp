/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */
#include "main.h"
// @lc code=start
class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t == nullptr)
                res += "null,";
            else {
                res += to_string(t->val) + ",";
                q.push(t->left);
                q.push(t->right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        vector<TreeNode *> nodes;
        int start = 0;
        while (true) {
            auto end = data.find(',', start);
            if (end == string::npos)
                break;
            string sub = data.substr(start, end - start);
            if (sub == "null")
                nodes.push_back(nullptr);
            else
                nodes.push_back(new TreeNode(stoi(sub)));
            start = end + 1;
        }

        auto root = nodes[0], cur = root;
        for (int i = 1, j = 1; j < nodes.size() && i < nodes.size(); j++) {
            if (cur == nullptr) {
                cur = nodes[j];
                continue;
            }
            cur->left = nodes[i];
            cur->right = nodes[i + 1];
            cur = nodes[j];
            i += 2;
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
