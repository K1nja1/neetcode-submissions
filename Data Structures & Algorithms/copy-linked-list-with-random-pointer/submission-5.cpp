/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr)
        return nullptr;
        Node* temp=head;
        while(temp){
            Node* newNode=new Node(temp->val);
            newNode->next=temp->next;
            temp->next=newNode;
            temp=newNode->next;
        }
        Node* curr=head->next;
        Node* prev=head;
        while(true){
            if(prev->random==nullptr) curr->random=nullptr;
            else curr->random=prev->random->next;
            if(!curr->next) break;
            curr=curr->next->next;
            prev=prev->next->next;
        }
        Node* res=head->next;
        curr=head->next;
        prev=head;
        while(true){
            prev->next=curr->next;
            if(!curr->next) break;
            curr->next=prev->next->next;
            prev=prev->next;
            curr=curr->next;
        }
        return res;
    }
};
