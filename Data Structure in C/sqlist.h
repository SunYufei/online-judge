#ifndef SQLIST_H_
#define SQLIST_H_

#include <bits/stdc++.h>
using namespace std;

typedef int ElemType;
typedef vector<ElemType> SqList;

bool InitList(SqList &);
bool ListInsert(SqList &, int, ElemType);
bool ListDelete(SqList &, int, ElemType &);

#endif