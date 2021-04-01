#ifndef STACK_H_
#define STACK_H_

#include <stdlib.h>

typedef struct {
    int x;
    int y;
} PosType;

typedef struct {
    int ord;
    PosType seat;
    int dir;
} ElemType;

typedef struct Node {
    ElemType data;
    struct Node* next;
} Node;

typedef Node* Stack;

void InitStack(Stack* s) {
    *s = (Node*)malloc(sizeof(Node));
    (*s)->next = NULL;
}

bool StackEmpty(Stack s) {
    return s->next == NULL;
}

void Push(Stack s, ElemType e) {
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = e;
    t->next = s->next;
    s->next = t;
}

bool Top(Stack s, ElemType* top) {
    if (StackEmpty(s))
        return false;
    *top = s->next->data;
    return true;
}

bool Pop(Stack s, ElemType* top) {
    if (StackEmpty(s))
        return false;
    Top(s, top);
    Node* t = s->next;
    s = s->next;
    free(t);
    return true;
}

void DeleteStack(Stack s) {
    if (s != NULL) {
        DeleteStack(s->next);
        free(s);
    }
}

#endif