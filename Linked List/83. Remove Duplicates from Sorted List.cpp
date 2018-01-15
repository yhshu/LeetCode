/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
	ListNode *deleteDuplicates(ListNode *head) {
		if (!head || !head->next)return head;// 考虑head的长度为0或1
		ListNode *node = head;
		while (node != nullptr && node->next != nullptr) // 判断node->next是否为空前，先判断node是否为空
		{
			if (node->val == node->next->val) // 如果node与node->next相等，node位置不改变，仅修改node->next
				node->next = node->next->next;
			else node = node->next;
		}
		return head;
	}
};