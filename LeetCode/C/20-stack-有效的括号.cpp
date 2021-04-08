/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include "main.h"
// @lc code=start
class Solution {
  public:
    bool isValid(string s) {
        if (s.empty())
            return true;
        stack<char> st;
        for (char c : s) {
            if (c == '(')
                st.push(')');
            else if (c == '[')
                st.push(']');
            else if (c == '{')
                st.push('}');
            else if (c == ')' || c == ']' || c == '}') {
                if (st.empty() || st.top() != c)
                    return false;
                st.pop();
            } else
                return false;
        }
        return st.empty();
    }
};
// @lc code=end
