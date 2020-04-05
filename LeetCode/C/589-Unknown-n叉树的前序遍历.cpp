/*
 * @lc app=leetcode.cn id=589 lang=cpp
 *
 * [589] N叉树的前序遍历
 */
#include "main.h"

// @lc code=start
class Solution {
  public:
    vector<int> preorder(Node *root) {
        if (root == nullptr)
            return {};
        vector<int> res;
        stack<Node *> st;
        st.push(root);
        while (!st.empty()) {
            Node *t = st.top();
            st.pop();
            res.push_back(t->val);
            for (int i = t->children.size() - 1; i >= 0; --i)
                if (t->children[i])
                    st.push(t->children[i]);
        }
        return res;
    }
};
// @lc code=end
