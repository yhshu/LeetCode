/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return head;
        unordered_map<Node*, Node*> m; // old node -> new node
        
        Node *newHead = new Node(head->val);
        m[head] = newHead;

        Node* cur = head->next;
        while(cur != NULL) {
            Node* newNode = new Node(cur->val);
            m[cur] = newNode;
            cur = cur->next;
            // no link for newNode now
        }

        cur = head;
        while(cur != NULL) {
            m[cur]->next = m[cur->next];
            m[cur]->random = m[cur->random];
            cur = cur->next;
        }
        return newHead;
    }
};
