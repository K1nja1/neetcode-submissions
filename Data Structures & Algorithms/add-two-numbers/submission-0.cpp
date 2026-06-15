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
        ListNode* newHead=new ListNode(0);
        ListNode* curr = newHead;
        int carry=0;
        while(l1 || l2 || carry){
            int v1,v2;
            if(l1) v1=l1->val;
            else v1=0;
            if(l2) v2=l2->val;
            else v2=0;
            int val=v1+v2+carry;
            carry=val/10;
            val=val%10;
            curr->next= new ListNode(val);
            if(l1) l1=l1->next;
            if(l2) l2=l2->next;
            curr=curr->next;
        }
        ListNode* res=newHead->next;
        return res;
    }
};
