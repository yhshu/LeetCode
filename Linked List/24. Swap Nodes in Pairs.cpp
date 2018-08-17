/*
Given a linked list, swap every two adjacent nodes and return its head.

Example:

Given 1->2->3->4, you should return the list as 2->1->4->3.
Note:

Your algorithm should use only constant extra space.
You may not modify the values in the list's nodes, only nodes itself may be changed.
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode **pp = &head; // pointer to pointer
        ListNode *a, *b;
        while ((a = *pp) && (b = a->next)) { // 为 null 时停止
            a->next = b->next; // a->next = c
            b->next = a;
            *pp = b; // head = b
            pp = &(a->next); // p = &c
        }
        return head;
    }
};