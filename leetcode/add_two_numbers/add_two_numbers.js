/**
 * ## Add Two Numbers
 * 
 * > LeetCode (Medium) https://leetcode.com/problems/add-two-numbers/description/
 * 
 * > Question: 
 * You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 * 
 * You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 * 
 * > Example
 * ```
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 * ```
 */

// Definition for singly-linked list.
// function ListNode(val) {
//   this.val = val;
//   this.next = null;
// }

/**
 * @param {ListNode} l1
 * @param {ListNode} l2
 * @return {ListNode}
 */
var addTwoNumbers = function(l1, l2) {
  let result_pointer = new ListNode(null), result_first = result_pointer, carry = 0;

  // *attention* the distinguish between `0` and `null`
  while (l1 !== null || l2 !== null || carry) {

    result_pointer.val = (safeAdd(l1, l2) + carry) % 10;
    carry = Math.floor((safeAdd(l1, l2) + carry) / 10);
    
    l1 = whatsNext(l1);
    l2 = whatsNext(l2);
    
    // move pointer
    (l1 || l2 || carry) && (result_pointer.next = new ListNode(null));
    (l1 || l2 || carry) && (result_pointer = result_pointer.next);
  }

  return result_first;
};

function whatsNext(temp_l) {
  temp_l && (temp_l.next !== null ? temp_l = temp_l.next : temp_l = null);
  return temp_l;
}


// 1 + null = 1
// 1 + undefined = 1
function safeAdd(a, b) {
  return (a ? a.val : 0) + (b ? b.val : 0);
}