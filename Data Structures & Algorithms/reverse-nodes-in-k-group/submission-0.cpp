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
        ListNode* tempH = head;
        ListNode* temp = head;
        int count = 0;

        while (temp) {
            count++;
            temp=temp->next;
        }

        count=count/k;

        if (count == 0) return head;

        ListNode* curr=head;
        ListNode* finalHead=nullptr;
        ListNode* prevTail=nullptr;

        for (int i = 0; i < count; i++) {
            ListNode* currHead=curr;
            ListNode* groupHead=curr;

            for (int j=1; j<k;j++) {
                ListNode* temp=curr->next;

                curr->next=temp->next;
                temp->next=groupHead;
                groupHead=temp;
            }

            if (i==0)finalHead = groupHead;
            else
                prevTail->next = groupHead;
            
            prevTail = currHead;
            curr = currHead->next;
        }

        return finalHead;
    }
};
