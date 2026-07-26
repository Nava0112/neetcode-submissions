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
    ListNode* merge2(ListNode* l, ListNode* r){
        ListNode* ans = new ListNode(0);
        ListNode* res = ans;
        while(l && r){
            if(l->val<=r->val){
                ans -> next = l;
                l=l->next;
            }
            else {
                ans->next=r;
                r=r->next;
            }
            ans=ans->next;
        }
        while(l){
            ans->next=l;
            ans=ans->next;
            l=l->next;
        }
        while(r){
            ans->next=r;
            ans=ans->next;
            r=r->next;
        }
        return res->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return {};
        if(n==1) return lists[0];
        ListNode* ans = lists[0];
        for(int i=1; i<n; i++){
            ans = merge2(ans, lists[i]);
        }
        return ans;
    }
};
