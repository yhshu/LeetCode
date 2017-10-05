/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* cur = head;
		ListNode* pre = new ListNode(0);
		pre->next = cur;
		while (cur)
		{
			if (cur->val == val)
			{
				ListNode *next = cur->next;
				if (head == cur)
					head = next;
				delete cur;
				cur = next;
				pre->next = cur;
			}
			else
			{
				pre = pre->next;
				cur = cur->next;
			}
		}
		return head;
	}
};