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
        ListNode* dummy = head;
        int cnt=0;
        while(dummy){
            dummy=dummy->next;
            cnt++;
        }
        dummy=head;
        if(n==cnt) return head->next;
        if(cnt==1) return nullptr;
        for(int i=0; i<cnt-n-1; i++){
            dummy=dummy->next;
        }
        ListNode* nxt = dummy->next->next;
        cout<<dummy->val;
        dummy->next=nxt;
        return head;
    }
};
