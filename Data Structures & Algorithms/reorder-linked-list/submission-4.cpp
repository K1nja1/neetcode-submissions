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
        ListNode *fast=head,*slow=head;
        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        
        ListNode *prev=nullptr;
        ListNode *temp=slow;
        slow=slow->next;
        temp->next=NULL;

        while(slow){
            ListNode* temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
        slow=head;
        ListNode* temp1=slow->next;
        ListNode* temp2=prev->next;
        while(prev){
            ListNode* temp1=slow->next;
            ListNode* temp2=prev->next;
            slow->next=prev;
            prev->next=temp1;
            slow=temp1;
            prev=temp2;
        }

    }
};
