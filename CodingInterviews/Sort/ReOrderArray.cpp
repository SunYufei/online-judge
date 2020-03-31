#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void reOrderArray(vector<int> &array) {
        queue<int> a, b;
        for (int i : array) {
            if (i & 1 == 1)
                a.push(i);
            else
                b.push(i);
        }
        int p = 0;
        while (!a.empty()) {
            array[p++] = a.front();
            a.pop();
        }
        while (!b.empty()) {
            array[p++] = b.front();
            b.pop();
        }
    }
};