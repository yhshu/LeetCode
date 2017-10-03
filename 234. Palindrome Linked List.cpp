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
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL)//没有元素或只有1个元素
			return true;
		
		while (head != NULL)
		{
			s1.push(head->val); 
            head= head->next;
		}
		bool odd =( s1.size() % 2);
		for (int i = 1; i <= s1.size() / 2; ++i)
		{
			s2.push(s1.top());
			s1.pop();
		}
		if (odd)
			s1.pop();
		for (int i = 1; i <= s1.size(); ++i)
		{
			if (s1.top() != s2.top())
				return false;
			s1.pop(); s2.pop();
		}
		return true;
	}
    
private:
    stack<int> s1;
	stack<int> s2;
};