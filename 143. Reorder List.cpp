/*
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
 */

 /**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 // 最后的顺序是：1, 倒数1, 2, 倒数2, 3, 倒数3, ……
class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head || !head->next || !head->next->next)
			return;
		// 找到链表中点
		ListNode *slow = head, *fast = head;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		// 如果链表有偶数个结点，slow停在第n/2个结点
		// 如果链表有奇数个结点，slow停在第n/2 + 1个结点

		// 将链表分为两半，将后半段逆转，slow是前半段链表最后一个结点
		ListNode *head2 = slow->next;
		slow->next = nullptr;

		ListNode *p = head2->next;
		head2->next = nullptr;
		while (p)
		{
			ListNode *next = p->next;
			p->next = head2;
			head2 = p;
			p = next;
		}

		// 合并两段链表
		ListNode *p1 = head, *p2 = head2;
		for (; p2;)
		{
			auto next = p1->next;
			p1 = p1->next = p2;
			p2 = next;
		}
	}
};