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
        ListNode* ans=new ListNode(0);
        ListNode* dummy =ans;
        while(l1 || l2 || carry){
            int a=(l1)?l1->val:0;
            int b=(l2)?l2->val:0;
            int sum = a+b+carry;
            carry=sum/10;
            sum%=10;
            ans->next = new ListNode(sum);
            ans=ans->next;
            l1 = (l1) ? l1->next : nullptr;
            l2 = (l2) ? l2->next : nullptr;
        }
        return dummy->next;
    }
};
