#include "main.h"

class Solution {
  public:
    vector<int> FindNumbersWithSum(vector<int> array, int sum) {
        int a = 1, b = INT_MAX;
        unordered_set<int> st;
        for (int num : array) {
            if (st.count(sum - num) != 0)
                if (num * (sum - num) < a * b) {
                    a = min(num, sum - num);
                    b = max(num, sum - num);
                }
            st.insert(num);
        }
        if (b != INT_MAX)
            return {a, b};
        else
            return {};
    }
};