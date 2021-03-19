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

void InitStack(Stack* s);

bool StackEmpty(Stack s);

void Push(Stack s, ElemType e);

bool Pop(Stack s, ElemType* e);

bool Top(Stack s, ElemType* e);

void DeleteStack(Stack s);

#endif