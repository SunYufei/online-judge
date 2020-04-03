/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
  public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        int len = digits.size();
        for (int i = len - 1; i >= 0; --i) {
            int t = carry + digits[i];
            digits[i] = t % 10;
            carry = t / 10;
        }
        if (carry != 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};
// @lc code=end
