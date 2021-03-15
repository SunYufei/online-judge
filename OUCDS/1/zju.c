#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode* Polynomial;
struct PolyNode {
    int coef;
    int expon;
    Polynomial link;
};

void Attach(int c, int e, Polynomial* pRear) {
    // 申请一个新结点
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->coef = c;
    P->expon = e;
    P->link = NULL;
    // 将结点添加到 pRear
    (*pRear)->link = P;
    // 传地址的原因
    *pRear = P;
}

Polynomial ReadPoly() {
    int c, e, n;
    // 定义一个含头结点链表
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    Polynomial Rear = P;
    // 读入数据并尾插
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d", &c, &e);
        Attach(c, e, &Rear);
    }
    // 删除头结点
    Rear = P;
    P = P->link;
    free(Rear);
    return P;
}

void PrintPoly(Polynomial P) {
    int flag = 0;
    if (P == NULL) {
        printf("0 0\n");
        return;
    }
    while (P != NULL) {
        if (flag == 0) {
            flag = 1;
        } else {
            printf(" ");
        }
        printf("%d %d", P->coef, P->expon);
        P = P->link;
    }
    printf("\n");
}

Polynomial Add(Polynomial P1, Polynomial P2) {
    // 定义含头结点链表
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    // 指向链表的指针
    Polynomial Rear = P, t1 = P1, t2 = P2;
    // 链表相加
    while (t1 != NULL && t2 != NULL) {
        if (t1->expon == t2->expon) {
            if (t1->coef + t2->coef != 0)
                Attach(t1->coef + t2->coef, t1->expon, &Rear);
            t1 = t1->link;
            t2 = t2->link;
        } else if (t1->expon > t2->expon) {
            Attach(t1->coef, t1->expon, &Rear);
            t1 = t1->link;
        } else {
            Attach(t2->coef, t2->expon, &Rear);
            t2 = t2->link;
        }
    }
    // 剩余部分遍历尾插
    while (t1 != NULL) {
        Attach(t1->coef, t1->expon, &Rear);
        t1 = t1->link;
    }
    while (t2 != NULL) {
        Attach(t2->coef, t2->expon, &Rear);
        t2 = t2->link;
    }
    Rear->link = NULL;
    // 删除头结点
    Rear = P;
    P = P->link;
    free(Rear);
    return P;
}

Polynomial Mult(Polynomial P1, Polynomial P2) {
    if (P1 == NULL || P2 == NULL)
        return NULL;
    // 定义含头结点链表
    Polynomial P;
    P = (Polynomial)malloc(sizeof(struct PolyNode));
    P->link = NULL;
    // 指向链表的指针
    Polynomial Rear, t, t1, t2;
    Rear = P, t1 = P1, t2 = P2;
    // 用 P1 的第一项乘以 P2，构造基础的 P
    while (t2 != NULL) {
        Attach(t1->coef * t2->coef, t1->expon + t2->expon, &Rear);
        t2 = t2->link;
    }
    // P1 剩余项与 P2 相乘并与 P 相加
    t1 = t1->link;
    while (t1 != NULL) {
        t2 = P2;
        Rear = P;
        while (t2 != NULL) {
            int c = t1->coef * t2->coef;
            int e = t1->expon + t2->expon;
            // 定位找到合适的插入点
            while (Rear->link != NULL && Rear->link->expon > e)
                Rear = Rear->link;
            // 插入点
            if (Rear->link != NULL && Rear->link->expon == e) {
                if (Rear->link->coef + c != 0) {
                    Rear->link->coef += c;
                } else {
                    // 删除 0 系数项
                    t = Rear->link;
                    Rear->link = t->link;
                    free(t);
                }
            } else {
                t = (Polynomial)malloc(sizeof(struct PolyNode));
                t->coef = c;
                t->expon = e;
                t->link = Rear->link;
                Rear->link = t;
                Rear = Rear->link;
            }
            t2 = t2->link;
        }
        t1 = t1->link;
    }
    // 删除头结点
    Rear = P;
    P = P->link;
    free(Rear);
    return P;
}

int main() {
    Polynomial P1, P2, PP, PS;
    P1 = ReadPoly();
    P2 = ReadPoly();
    PP = Mult(P1, P2);
    PrintPoly(PP);
    PS = Add(P1, P2);
    PrintPoly(PS);
    return 0;
}