/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *mergeTwoLists(struct ListNode *l1, struct ListNode *l2) {
    struct ListNode *res = NULL, *pre = NULL;
    if (!l1)return l2;
    if (!l2)return l1;
    if (l1->val > l2->val) {
        res = l2;
        pre = l2;
        l2 = l2->next;
    } else {
        res = l1;
        pre = l1;
        l1 = l1->next;
    }
    while (l1 && l2) {
        if (l1->val > l2->val) {
            pre->next = l2;
            pre = l2;
            l2 = l2->next;
        } else {
            pre->next = l1;
            pre = l1;
            l1 = l1->next;
        }
    }
    if (!l1) {
        pre->next = l2;
        pre = l2;
    } else {
        pre->next = l1;
        pre = l1;
    }
    return res;
}