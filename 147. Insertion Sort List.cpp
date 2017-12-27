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
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode * new_head = new ListNode(0);
		new_head->next = head;
		ListNode *pre = new_head;
		ListNode *cur = head;
		while (cur)
		{
			if (cur->next && cur->val > cur->next->val)//如果 cur->next 比cur 小，需要将 cur->next 调整位置
			{
				while (pre->next && pre->next->val < cur->next->val)
					pre = pre->next;//找到 cur->next 应属于的位置
				// 将 cur->next 插入到 pre 后
				ListNode* temp = pre->next;
				pre->next = cur->next;
				cur->next = cur->next->next;
				pre->next->next = temp;
				// 将 pre 重新置于 new_head
				pre = new_head;
			}
			else
				cur = cur->next;
		}
		ListNode * res = new_head->next;
		delete new_head;
		return res;
	}
};