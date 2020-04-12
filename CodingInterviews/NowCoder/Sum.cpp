#include "main.h"

class Solution {
  public:
    int Sum_Solution(int n) {
        if ((n > 0) && ((n += Sum_Solution(n - 1)) > 0))
            ;
        return n;
    }
};