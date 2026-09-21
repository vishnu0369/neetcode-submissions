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
        Node *curr = new Node(0), *ans = curr, *temp = head;
        unordered_map<Node*,Node*>m;
        int i = 0;
        while(temp) {
            Node *n = new Node(temp->val);
            curr->next = n;
            curr = curr->next;
            m[temp] = n;
            temp = temp->next;
        }
        
        curr = ans->next;
        temp = head;

        while(curr) {
            curr->random = m[temp->random];
            curr = curr->next;
            temp=temp->next;
        }

        return ans->next;
    }
};