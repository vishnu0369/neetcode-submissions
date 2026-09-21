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

        while(l1 || l2 || carry) {
            int n1 = l1 ? l1->val : 0, n2 = l2 ? l2->val : 0, sum = n1 + n2 + carry;
            carry = sum/10;
            temp->next = new ListNode(sum%10);
            temp=temp->next;
            l1=l1 ? l1->next : NULL,l2= l2 ? l2->next : NULL;
        }

        return ans->next;
    }
};
