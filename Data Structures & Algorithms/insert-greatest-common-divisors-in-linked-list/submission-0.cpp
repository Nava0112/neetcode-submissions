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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head->next==nullptr) return head;
        vector<int>arr;
        ListNode* dum = head;
        int last = dum->val;
        dum = dum->next;
        while(dum){
            arr.push_back(gcd(dum->val, last));
            last=dum->val;
            dum=dum->next;
        }
        dum = head;
        for(int i=0; i<arr.size(); i++){
            ListNode* nxt = dum -> next;
            ListNode* temp = new ListNode(arr[i]);
            dum -> next = temp;
            temp->next = nxt;
            dum = nxt;
        }
        return head;
    }
};