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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()) return nullptr;
        ListNode* res=lists[0];
        if(lists.size()==2) return ListNodesort(lists[0],lists[1]);
        for(int i=1;i<lists.size();i++){
            res=ListNodesort(res,lists[i]);
        }
        return res;
    }
    ListNode* ListNodesort(ListNode* l1,ListNode* l2){
        ListNode* head;
        if(!l1) return l2;
        if(!l2) return l1;
            
        if(l1->val>l2->val) {head=l2; l2=l2->next;}
        else {head=l1; l1=l1->next;}
        ListNode* temp=head;
        while (l1 && l2){
            if(l1->val<l2->val){
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
            }
            else {
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
            }
        }
        if(l1) temp->next=l1;
        else if(l2) temp->next=l2;
        return head;

    }

};
