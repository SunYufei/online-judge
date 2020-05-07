class Node {
  public:
    int val;
    Node *left, *right;
    Node() {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr) {}
    Node(int _val, Node *_left, Node *_right)
        : val(_val), left(_left), right(_right) {}
};

class Solution {
  public:
    Node *treeToDoublyList(Node *root) {
        if (root == nullptr)
            return nullptr;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

  private:
    Node *pre, *head;

    void dfs(Node *cur) {
        if (cur == nullptr)
            return;
        dfs(cur->left);
        if (pre != nullptr)
            pre->right = cur;
        else
            head = cur;
        cur->left = pre;
        pre = cur;
        dfs(cur->right);
    }
};