#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

int main() {
    vector<int> v;
    vector<int>::iterator it;
    int t;
    bool flag = false;
    while (scanf("%d", &t))
        if (t != -1)
            v.push_back(t);
        else {
            if (flag)
                break;
            else
                flag = true;
        }
    if (v.size() == 0)
        cout << "NULL";
    else {
        sort(v.begin(), v.end());
        for (it = v.begin(); it < v.end() - 1; it++)
            cout << *it << " ";
        cout << *it;
    }
}