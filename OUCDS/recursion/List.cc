#include <stdio.h>

typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode, *List;

void do_something(List head);

void traverse(List head) {
    if (head == NULL)
        return;
    traverse(head->next);
    do_something(head);
}