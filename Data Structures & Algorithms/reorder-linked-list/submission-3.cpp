/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow=slow->next;
            fast=fast->next->next;
        }
        
        ListNode* curr = slow->next,*prev = NULL, *next;
        while(curr) {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }

        ListNode* temp = new ListNode(0), *ans = temp, *p1 = head, *p2 = prev;

        while(p2 != NULL) {
            temp->next = p1;
            p1=p1->next;
            temp=temp->next;
            temp->next = p2;
            p2=p2->next;
            temp=temp->next;
        }
        ListNode* x = ans->next;
        if(p1 != prev){
            temp->next = p1;
            temp=temp->next;
            temp->next=NULL;
        }

        head = ans->next;
    }
};
