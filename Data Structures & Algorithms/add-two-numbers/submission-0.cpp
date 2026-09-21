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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode *temp = new ListNode(0), *ans = temp;

        while(l1 && l2) {
            int n1 = l1->val, n2 = l2->val, sum = n1 + n2 + carry;
            carry = sum/10;
            temp->next = new ListNode(sum%10);
            temp=temp->next;
            l1=l1->next,l2=l2->next;
        }

        if(carry == 0 && l1) {
            temp->next = l1;
            l1 = NULL;
        }
        
        if(carry == 0 && l2) {
            temp->next = l2;
            l2 = NULL;
        }

        if(carry && l1) {
            while(l1) {
                int n1 = l1->val, sum = n1 + carry; carry = sum/10;
                temp->next = new ListNode(sum%10);
                temp=temp->next;
                l1=l1->next;
            }
        }
        
        
        if(carry && l2) {
            while(l2) {
                int n1 = l2->val, sum = n1 + carry; carry = sum/10;
                temp->next = new ListNode(sum%10);
                temp=temp->next;
                l2=l2->next;
            }
        }
        if(carry){
            temp->next = new ListNode(carry);
            temp = temp->next;
        }
        return ans->next;
    }
};
