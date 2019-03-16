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
    void swap(ListNode* &l1, ListNode* &l2) {
        ListNode *t = l1;
        l1 = l2;
        l2 = t;
    }
    
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        if(l1 -> val > l2 -> val)
            swap(l1, l2);
        
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        
        while(p1 -> next) {
            if(p1 -> next -> val > p2 -> val)
                swap(p1 -> next, p2);
            p1 = p1 -> next;                
        }
        
        p1 -> next = p2;
        return l1;        
    }
    
    ListNode* merge(vector<ListNode*>& lists, int l, int r) {
        if(l == r)
            return lists[l];
        if(r - l == 1)
            return mergeTwoLists(lists[l], lists[r]);
        return mergeTwoLists(merge(lists, l, l + (r - l) / 2), merge(lists, l + (r - l) / 2 + 1, r));
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return {};
        if(lists.size() == 1)
            return lists[0];
        ListNode* res = merge(lists, 0, lists.size() - 1);
        return res;
    }
};
