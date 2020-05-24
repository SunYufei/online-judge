/*
 * @lc app=leetcode.cn id=2 lang=javascript
 *
 * [2] 两数相加
 */
import { ListNode } from './main.js';
// @lc code=start
/**
 * Definition for singly-linked list.
 * function ListNode(val) {
 *     this.val = val;
 *     this.next = null;
 * }
 */
/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function (l1, l2) {
    let res = new ListNode(null);
    let t = res, carry = 0;
    while (l1 || l2) {
        carry = (l1 ? l1.val : 0) + (l2 ? l2.val : 0) + carry;
        t.next = new ListNode(carry % 10);
        t = t.next;
        carry = carry >= 10 ? 1 : 0;
        l1 && (l1 = l1.next);
        l2 && (l2 = l2.next);
    }
    carry && (t.next = new ListNode(carry));
    return res.next;
};
// @lc code=end

