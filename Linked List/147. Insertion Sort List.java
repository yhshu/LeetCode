/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode insertionSortList(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode newhead = new ListNode(0);
        newhead.next = head;
        ListNode pre = newhead;
        ListNode cur = head;
        while (cur != null) { // head到cur这段是当前的有序部分
            if (cur.next != null && cur.val > cur.next.val) // 需要将cur.next插入到cur之前的有序链表
            {
                while (pre.next != null && pre.next.val < cur.next.val)
                    pre = pre.next;
                // cur.next应该被插入到pre之后
                ListNode t = pre.next;
                pre.next = cur.next;
                cur.next = cur.next.next;
                pre.next.next = t;
                // 将 pre 重新置为 newhead
                pre = newhead;
            } else
                cur = cur.next;
        }
        return newhead.next;
    }
}