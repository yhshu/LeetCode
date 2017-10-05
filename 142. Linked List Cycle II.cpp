/*
Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Note: Do not modify the linked list.
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
	ListNode *detectCycle(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
			return nullptr;
		ListNode *fast = head;
		ListNode *slow = head;
		ListNode *entry = head;
		while (fast->next && fast->next->next)
		{
			fast = fast->next->next;
			slow = slow->next;
			if (fast == slow)
			{
				while (slow != entry)
				{
					slow = slow->next;
					entry = entry->next;
				}
				return entry;
			}
		}
		return nullptr;
	}
};