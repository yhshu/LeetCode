/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr)
			return head;
		ListNode *new_head = new ListNode(-1);
		new_head->next = head;
		ListNode *slow = new_head;
		ListNode *fast = new_head;
		for (int i = 0; i < n; i++)
		{
			fast = fast->next;
		}
		while (fast->next)
		{
			slow = slow->next;
			fast = fast->next;
		}
		ListNode* deleted = slow->next;
		slow->next = slow->next->next;
		delete deleted;

		return new_head->next;
	}
};