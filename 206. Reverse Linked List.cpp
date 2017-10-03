//Reverse a singly linked list.

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
	ListNode* reverseList(ListNode* head) {
		if (!head)
			return head;
		ListNode* rear = head;
		head = head->next;
		rear->next = NULL;
		while (NULL != head)
		{
			ListNode* next = head->next;
			head->next = rear;
			rear = head;
			head = next;
		}
		return rear;
	}
};