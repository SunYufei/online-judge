//
//	Tree.h
//	树、二叉树、二叉排序树、平衡二叉排序树
//
//	2015-12-30
//
#ifndef TREE_H_
#define TREE_H_

#include <iostream>
using namespace std;

#define MAX(a, b) ((a) > (b) ? (a) : (b))

template <typename T> struct BTNode {
    BTNode *lchild;
    T data;
    BTNode *rchild;
};

template <typename T> class BTree {
  protected:
    BTNode<T> *root;

    //先序遍历
    void pre_order(void (*visit)(T), BTNode<T> *t) {
        if (NULL != t) {
            // D
            visit(t->data);
            // L
            pre_order(visit, t->lchild);
            // R
            pre_order(visit, t->rchild);
        }
    }

    //中序遍历
    void in_order(void (*visit)(T), BTNode<T> *t) {
        if (NULL != t) {
            // L
            in_order(visit, t->lchild);
            // D
            visit(t->data);
            // R
            in_order(visit, t->rchild);
        }
    }

    //后序遍历
    void post_order(void (*visit)(T), BTNode<T> *t) {
        if (NULL != t) {
            // L
            post_order(visit, t->lchild);
            // R
            post_order(visit, t->rchild);
            // D
            visit(t->data);
        }
    }

    //结点个数
    int nodes(BTNode<T> *t) {
        if (NULL == t) {
            return 0;
        } else {
            return 1 + nodes(t->lchild) + nodes(t->rchild);
        }
    }

    //叶子结点个数
    int leaf_nodes(BTNode<T> *t) {
        int count = 0;
        if (NULL == t->lchild && NULL == t->rchild) {
            ++count;
        } else {
            count += leaf_nodes(t->lchild);
            count += leaf_nodes(t->rchild);
        }
        return count;
    }

    //二叉树深度
    int depth(BTNode<T> *t) {
        if (NULL == t) {
            return 0;
        } else {
            return 1 + MAX(depth(t->lchild), depth(t->rchild));
        }
    }

    //销毁二叉树
    void destroy(BTNode<T> *t) {
        if (NULL != t) {
            if (NULL != t->lchild) //有左孩子
            {
                destroy(t->lchild); //销毁左孩子
            }
            if (NULL != t->rchild) //有右孩子
            {
                destroy(t->rchild); //销毁右孩子
            }
            delete t; //销毁根结点
            t = NULL;
        }
    }

    //括号表示法
    void disp_by_bracket(BTNode<T> *t, ostream &os = cout) {
        if (NULL == t) {
            return;
        }
        os << t->data;
        if (NULL != t->lchild || NULL != t->rchild) {
            os << '(';
            disp_by_bracket(t->lchild, os);
            os << ',';
            disp_by_bracket(t->rchild, os);
            os << ')';
        }
    }

  public:
    //构造函数
    BTree() : root(NULL) {}

    //析构函数
    ~BTree() { destroy(root); }

    //先序遍历
    void pre_order(void (*visit)(T)) { pre_order(visit, root); }

    //中序遍历
    void in_order(void (*visit)(T)) { in_order(visit, root); }

    //后序遍历
    void post_order(void (*visit)(T)) { post_order(visit, root); }

    //结点个数
    int nodes() { return nodes(root); }

    //叶子结点个数
    int leaf_nodes() { return leaf_nodes(root); }

    //二叉树深度
    int depth() { return depth(root); }

    //括号表示法输出
    void disp_by_bracket(ostream &os = cout) { disp_by_bracket(root, os); }
};

template <typename T> class BST : public BTree<T> {
  public:
    //查找元素
    BTNode<T> *search(const T key) { return search(root, key); }
    //插入结点
    void insert(const T data) { insert(root, data); }
    //删除节点
    void delete_data(const T key) { delete_data(root, key); }

  protected:
    //查找元素
    BTNode<T> *search(BTNode<T> *t, const T key) {
        if (NULL == t || key == t->data) {
            return t;
        } else if (key < t->data) {
            return search(t->lchild, key);
        } else {
            return search(t->rchild, key);
        }
    }

    //插入结点
    void insert(BTNode<T> *&t, const T data) {
        if (NULL != search(data)) {
            return;
        }
        if (NULL == t) {
            t = new BTNode<T>;
            t->data = data;
            t->lchild = t->rchild = NULL;
        } else if (data < t->data) {
            insert(t->lchild, data);
        } else {
            insert(t->rchild, data);
        }
    }

    //删除节点
    void delete_data(BTNode<T> *&t, const T key) {
        if (NULL == t) {
            return;
        } else {
            if (key == t->data) {
                BTNode<T> *q;
                if (NULL == t->rchild) {
                    q = t;
                    t = t->rchild;
                    delete q;
                } else if (NULL == t->lchild) {
                    q = t;
                    t = t->rchild;
                    delete q;
                } else {
                    q = t;
                    BTNode<T> *s = t->lchild;
                    while (NULL != s->rchild) {
                        q = s;
                        s = s->rchild;
                    }
                    t->data = s->data;
                    if (q != t) {
                        q->rchild = s->lchild;
                    } else {
                        q->lchild = s->lchild;
                    }
                    delete s;
                } // else
            }     // if
            else if (key < t->data) {
                delete_data(t->lchild, key);
            } else {
                delete_data(t->rchild, key);
            }
        } // else
    }
};

#endif