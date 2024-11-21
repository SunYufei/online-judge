#
# @lc app=leetcode.cn id=345 lang=python3
#
# [345] 反转字符串中的元音字母
#
# https://leetcode.cn/problems/reverse-vowels-of-a-string/description/
#
# algorithms
# Easy (55.29%)
# Likes:    363
# Dislikes: 0
# Total Accepted:    213.3K
# Total Submissions: 385.6K
# Testcase Example:  '"IceCreAm"'
#
# 给你一个字符串 s ，仅反转字符串中的所有元音字母，并返回结果字符串。
#
# 元音字母包括 'a'、'e'、'i'、'o'、'u'，且可能以大小写两种形式出现不止一次。
#
#
#
# 示例 1：
#
#
# 输入：s = "IceCreAm"
#
# 输出："AceCreIm"
#
# 解释：
#
# s 中的元音是 ['I', 'e', 'e', 'A']。反转这些元音，s 变为 "AceCreIm".
#
#
# 示例 2：
#
#
# 输入：s = "leetcode"
#
# 输出："leotcede"
#
#
#
#
# 提示：
#
#
# 1 <= s.length <= 3 * 10^5
# s 由 可打印的 ASCII 字符组成
#
#
#


# @lc code=start
class Solution:
    def reverseVowels(self, s: str) -> str:
        m = set(["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"])
        s = list(s)
        l, r = 0, len(s) - 1
        while l < r:
            while s[l] not in m and l < r:
                l += 1
            while s[r] not in m and l < r:
                r -= 1
            s[l], s[r] = s[r], s[l]
            l, r = l + 1, r - 1
        return "".join(s)


# @lc code=end
