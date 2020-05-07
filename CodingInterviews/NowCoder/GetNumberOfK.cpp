#include "main.h"

class Solution {
  public:
    int GetNumberOfK(vector<int> data, int k) {
        if (data.empty() || k < data[0] || k > *(data.end() - 1))
            return 0;
        int l = 0, r = data.size() - 1;
        while (l <= r) {
            int m = l + (r - l) >> 1;
            if (data[m] < k)
                l = m + 1;
            else if (data[m] > k)
                r = m - 1;
            else {
                int i = m, j = m;
                while (i >= 0 && data[i] == k)
                    --i;
                while (j < data.size() && data[j] == k)
                    ++j;
                return j - i - 1;
            }
        }
        return 0;
    }
};