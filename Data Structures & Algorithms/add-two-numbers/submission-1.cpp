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
        int carry =0;
        ListNode* ans = new ListNode(0);
        ListNode* res = ans;
        while(l1 || l2 || carry){
            int a=0; int b=0;
            if(l1){
                a=l1->val;
                l1=l1->next;
            }
            if(l2){
                b=l2->val;
                l2=l2->next;
            }
            int sum = a+b+carry;
            carry = sum/10;
            sum%=10;
            ListNode* temp = new ListNode(sum);
            ans -> next = temp;
            ans=ans->next;
        }
        return res->next;
    }
};
