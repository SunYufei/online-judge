#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *PtrToNode;
struct Node {
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode List;

List Read();        /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main() {
    List L1, L2, L;
    L1 = Read();
    L2 = Read();
    L = Merge(L1, L2);
    Print(L);
    Print(L1);
    Print(L2);
    return 0;
}

List Merge(List L1, List L2) {
    List p, p1, p2, t, head;
    p1 = L1->Next, p2 = L2->Next;
    head = (List)malloc(sizeof(struct Node));
    p = head;
    while (p1 && p2) {
        if (p1->Data <= p2->Data) {
            p->Next = p1;
            p1 = p1->Next;
        } else {
            p->Next = p2;
            p2 = p2->Next;
        }
        p = p->Next;
    }
    p->Next = p1 ? p1 : p2;
    L1->Next = L2->Next = NULL;
    return head;
}