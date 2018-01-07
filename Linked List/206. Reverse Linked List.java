/**
 * Definition for singly-linked list.
 * public class ListNode {
 * int val;
 * ListNode next;
 * ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null)
            return head;
        ListNode rear = null;
        while (head != null) {
            ListNode next = head.next;
            head.next = rear;
            rear = head;
            head = next;
        }
        return rear;
    }
}