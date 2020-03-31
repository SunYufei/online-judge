#ifndef LISTNODE_H_
#define LISTNODE_H_

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

#endif