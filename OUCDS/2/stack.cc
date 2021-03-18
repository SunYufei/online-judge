#include "stack.h"

void InitStack(Stack& s) {
    s = (Node*)malloc(sizeof(Node));
    s->next = NULL;
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

bool Pop(Stack s, ElemType& top) {
    if (StackEmpty(s) == true)
        return false;
    Node* t = s->next;
    top = t->data;
    s->next = t->next;
    free(t);
    return true;
}

bool Top(Stack s, ElemType& top) {
    if (StackEmpty(s))
        return false;
    top = s->next->data;
    return true;
}

void DeleteStack(Stack s) {
    if (s != NULL) {
        DeleteStack(s->next);
        free(s);
    }
}