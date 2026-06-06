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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* ans = new ListNode(0);
        ListNode* res=ans;
        ListNode* curr=head;
        ListNode* dummy = head;
        int cnt = 0;
        while(dummy){
            cnt++;
            dummy = dummy->next;
        }
        int n=cnt/k;
        for(int i=0; i<n; i++){
            ListNode* prev=nullptr;
            for(int i=0; i<k; i++){
                ListNode* nxt = curr->next;
                curr->next=prev;
                prev=curr;
                curr=nxt;
            }
            ans->next=prev;
            while(ans->next) ans=ans->next;
        }
        if(n*k!=cnt) ans->next=curr;
        return res->next;
    }
};
