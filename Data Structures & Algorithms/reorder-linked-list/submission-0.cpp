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
        stack<int>st;
        ListNode* temp = head;
        ListNode* ans = new ListNode(0), *res = ans;
        int cnt = 0;
        while(temp) {
            cnt++;
            st.push(temp->val);
            temp=temp->next;
        }

        for(int i=0;i<cnt/2;i++) {
            ans->next = head;
            ans=ans->next;
            head=head->next;
            ans->next= new ListNode(st.top());
            st.pop();
            ans=ans->next;
        }

        if(cnt%2==1)
            ans->next = new ListNode(st.top());
        head = res->next;
    }
};
