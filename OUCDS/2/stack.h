#ifndef STACK_H_
#define STACK_H_

#include <stdlib.h>

typedef int ElemType;

typedef struct Node {
    ElemType data;
    struct Node* next;
} Node;

typedef Node* Stack;

void InitStack(Stack&);

bool StackEmpty(Stack);

void Push(Stack, ElemType);

bool Pop(Stack, ElemType&);

bool Top(Stack, ElemType&);

void DeleteStack(Stack);

#endif