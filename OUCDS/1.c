#include <stdio.h>
#include <stdlib.h>

// 结点定义
typedef struct Node {
    int coef;
    int exp;
    struct Node* next;
} Node;

// 链表定义
typedef Node* List;

Node* new_node() {
    Node* res = (Node*)malloc(sizeof(Node));
    res->next = NULL;
    return res;
}

List read_list() {
    int n;
    scanf("%d", &n);
    // 含头结点链表
    List res = new_node();
    Node* p = res;
    // 读数据
    while (n--) {
        // 申请一个新的结点
        Node* t = new_node();
        // 读数据
        scanf("%d %d", &(t->coef), &(t->exp));
        // 添加到链表中
        p->next = t;
        p = p->next;
    }
    // 删除头结点
    p = res;
    res = res->next;
    free(p);
    return res;
}

List add_list(List l1, List l2) {
    // 含头结点链表
    List res = new_node();
    Node* p = res;
    // 相加
    while (l1 != NULL && l2 != NULL) {
        Node* t = new_node();
        if (l1->exp == l2->exp) {
            // l1, l2 系数相同
            t->coef = l1->coef + l2->coef;
            t->exp = l1->exp;
            l1 = l1->next;
            l2 = l2->next;
        } else if (l1->exp > l2->exp) {
            // l1 系数 > l2
            t->coef = l1->coef;
            t->exp = l1->exp;
            l1 = l1->next;
        } else {
            // l1 系数 < l2
            t->coef = l2->coef;
            t->exp = l2->exp;
            l2 = l2->next;
        }
        if (t->coef == 0) {
            // 零结点不尾插
            free(t);
        } else {
            // 结点尾插
            p->next = t;
            p = p->next;
        }
    }
    // 剩余，遍历尾插结点
    Node* r = l1 != NULL ? l1 : l2;
    while (r != NULL) {
        Node* t = new_node();
        t->coef = r->coef;
        t->exp = r->exp;
        p->next = t;
        p = p->next;
        r = r->next;
    }
    // 删除头结点
    p = res;
    res = res->next;
    free(p);
    return res;
}

List mul_list(List l1, List l2) {
    if (l1 == NULL || l2 == NULL)
        return NULL;
    // 含头结点链表
    List res = new_node();
    Node *p = res, *p1, *p2;
    // 使用 l1 第一项与 l2 相乘构造初始链表
    p1 = l1, p2 = l2;
    while (p2 != NULL) {
        Node* t = new_node();
        t->coef = p1->coef * p2->coef;
        t->exp = p1->exp + p2->exp;
        p->next = t;
        p = p->next;
        p2 = p2->next;
    }
    // l1 剩余项与 l2 相乘并与 res 相加
    p1 = p1->next;
    while (p1 != NULL) {
        p2 = l2;
        p = res;
        while (p2 != NULL) {
            int c = p1->coef * p2->coef;
            int e = p1->exp + p2->exp;
            // 定位到合适的点
            while (p->next != NULL && p->next->exp > e)
                p = p->next;
            // 插入点
            if (p->next != NULL && p->next->exp == e) {
                // 消除 0 系数项
                if (p->next->coef + c != 0) {
                    p->next->coef += c;
                } else {
                    Node* t = p->next;
                    p->next = t->next;
                    free(t);
                }
            } else {
                Node* t = new_node();
                t->coef = c;
                t->exp = e;
                t->next = p->next;
                p->next = t;
                p = p->next;
            }
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    // 删除头结点
    p = res;
    res = res->next;
    free(p);
    return res;
}

void print_list(List l) {
    // 空链表输出 0
    if (l == NULL) {
        printf("0 0\n");
        return;
    }
    // 非空链表，递归输出
    printf("%d %d", l->coef, l->exp);
    if (l->next != NULL) {
        printf(" ");
        print_list(l->next);
    } else {
        printf("\n");
    }
}

void delete_list(List l) {
    if (l != NULL) {
        delete_list(l->next);
        free(l);
    }
}

int main() {
    List l1, l2, la, lm;
    l1 = read_list();
    l2 = read_list();
    // mul
    lm = mul_list(l1, l2);
    print_list(lm);
    // add
    la = add_list(l1, l2);
    print_list(la);
    // delete
    delete_list(l1);
    delete_list(l2);
    delete_list(la);
    delete_list(lm);
    return 0;
}