#pragma once

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

struct Node {
    int val;
    vector<Node *> children;
    Node() {}
    Node(int _val) : val(_val) {}
    Node(int _val, vector<Node *> _children) : val(_val), children(_children) {}
};
