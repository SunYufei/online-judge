#include "main.h"

class Codec {
  public:
    string serialize(TreeNode *root) {
        if (root == nullptr)
            return "";
        string res;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            auto t = q.front();
            q.pop();
            if (t) {
                res += to_string(t->val) + ",";
                q.emplace(t->left);
                q.emplace(t->right);
            } else
                res += "null,";
        }
        return res;
    }

    TreeNode *deserialize(string data) {
        if (data.empty())
            return nullptr;
        vector<TreeNode *> nodes;
        // split
        int start = 0;
        while (true) {
            auto end = data.find(',', start);
            if (end == string::npos)
                break;
            string sub = data.substr(start, end - start);
            if (sub == "null")
                nodes.emplace_back(nullptr);
            else
                nodes.emplace_back(new TreeNode(stoi(sub)));
            start = end + 1;
        }
        // build
        auto root = nodes[0], cur = root;
        for (int i = 1, j = 1; i < nodes.size() && j < nodes.size(); i++) {
            if (cur == nullptr) {
                cur = nodes[i];
                continue;
            }
            cur->left = nodes[j];
            cur->right = nodes[j + 1];
            cur = nodes[i];
            j += 2;
        }
        return root;
    }
};