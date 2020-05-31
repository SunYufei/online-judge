#include "main.h"

class Solution {
  public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (rotateArray.empty())
            return 0;
        int l = 0, r = rotateArray.size() - 1;
        while (rotateArray[l] == rotateArray[r] && l <= r)
            ++l, --r;
        while (rotateArray[l] > rotateArray[r]) {
            int m = (l + r) >> 1;
            if (rotateArray[l] <= rotateArray[m])
                l = m + 1;
            else if (rotateArray[m] <= rotateArray[r])
                r = m;
        }
        return rotateArray[l];
    }
};