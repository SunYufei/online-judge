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
        stack<char> st;
        for (char c : s) {
            if (c == '(')
                st.emplace(')');
            else if (c == '[')
                st.emplace(']');
            else if (c == '{')
                st.emplace('}');
            else if (c == ')' || c == ']' || c == '}') {
                if (!st.empty() && c == st.top())
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }
};
// @lc code=end
