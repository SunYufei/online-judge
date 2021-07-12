typedef struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode, *Tree;

void do_something(Tree root);

void traverse(Tree root) {
    if (root == NULL)
        return;
    do_something(root);
    traverse(root->left);
    traverse(root->right);
}

int depth(Tree root) {
    if (root == NULL)
        return 0;
    int dl = depth(root->left);
    int dr = depth(root->right);
    return 1 + dl > dr ? dl : dr;
}

bool is_symm(Tree t1, Tree t2) {
    if (t1 == NULL && t2 == NULL)
        return true;
    if (t1 == NULL || t2 == NULL)
        return false;
    if (t1->data != t2->data)
        return false;
    return is_symm(t1->left, t2->left) && is_symm(t1->right, t2->right);
}