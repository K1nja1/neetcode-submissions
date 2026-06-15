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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        ListNode *res=nullptr;
        if(list1->val<list2->val){
            res=list1;
            list1=list1->next;
        }
        else { res=list2; list2=list2->next;}
        ListNode* head = res;
        while(list1 && list2){
            if(list1->val < list2->val){
                res->next=list1;
                list1=list1->next;
            }
            else { res->next=list2; list2=list2->next;}
            res=res->next;
        }
        if (list1){
        res->next=list1;
        } else {
        res->next=list2;
        }
        return head;

    }
};
