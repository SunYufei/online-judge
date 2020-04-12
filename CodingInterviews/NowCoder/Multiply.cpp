#include "main.h"

class Solution {
  public:
    vector<int> multiply(const vector<int> &A) {
        if (A.size() == 0)
            return vector<int>();
        int size = A.size();
        vector<int> res(size);
        int t = 1;
        for (int i = 0; i < size; i++) {
            res[i] = t;
            t *= A[i];
        }
        t = 1;
        for (int i = size - 1; i >= 0; --i) {
            res[i] *= t;
            t *= A[i];
        }
        return res;
    }
};