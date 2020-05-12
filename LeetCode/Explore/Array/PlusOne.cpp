#include "../main.h"

class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1, size = digits.size();
        for (int i = size - 1; i >= 0; --i) {
            carry += digits[i];
            digits[i] = carry % 10;
            carry /= 10;
        }
        if (carry != 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};