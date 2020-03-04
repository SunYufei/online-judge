#include "sqlist.h"

bool InitList(SqList &L) { return true; }

bool ListInsert(SqList &L, int i, ElemType e) {
    if (i < 1 || i > L.size() + 1)
        return false;
    if (i == L.size() + 1)
        L.push_back(e);
    else {
        auto it = L.begin();
        while (--i > 0)
            ++it;
        L.insert(it, e);
    }
    return true;
}

bool ListDelete(SqList &L, int i, ElemType &e) {
    if (i < 1 || i > L.size())
        return false;
    auto it = L.begin();
    while (--i > 0)
        ++it;
    auto ret = L.erase(it);
    e = *ret;
    return true;
}

int LocateElem(SqList L, ElemType e) {}