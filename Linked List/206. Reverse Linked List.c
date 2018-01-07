/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *reverseList(struct ListNode *head) {
    if (head == NULL)
        return head;
    struct ListNode *rear = NULL;
    while (head != NULL) {
        struct ListNode *next = head->next;
        head->next = rear;
        rear = head;
        head = next;
    }
    return rear;
}