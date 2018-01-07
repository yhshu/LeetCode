/*
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *res = nullptr, *pre = nullptr;
        if (l1 == nullptr)return l2;
        if (l2 == nullptr)return l1;
        // Make res and pre equal the smaller one of l1 and l2
        if (l1->val > l2->val) {
            res = l2;
            pre = l2;
            l2 = l2->next;
        } else {
            res = l1;
            pre = l1;
            l1 = l1->next;
        }
        while (l1 && l2) // pre is always the last node of the merging list
        {
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
        // Now, l1 == nullptr or l2 == nullptr
        if (l1 == nullptr) {
            pre->next = l2;
            pre = l2;
        } else //if (l2 == nullptr)
        {
            pre->next = l1;
            pre = l1;
        }
        return res;
    }
};