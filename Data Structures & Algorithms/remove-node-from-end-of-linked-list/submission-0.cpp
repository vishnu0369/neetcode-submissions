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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* temp = head;
        while(temp) {
            len++;
            temp=temp->next;
        }

        int s = len - n + 1, pos = 0;

        if(s == 1) {
            head = head->next;
            return head;
        }

        temp = head;
        while(temp){
            pos++;
            if(pos == s-1) {
                temp->next = temp->next->next;
                break;
            }
            temp=temp->next;
        }
        return head;
    }
};
