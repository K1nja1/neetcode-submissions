class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        int key;

    Node(int key,int data){
        this->data=data;
        this->next=nullptr;
        this->prev=nullptr;
        this->key=key;
    }
    

};

class LRUCache {
public:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mp;
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mp.count(key)) {
            remove(mp[key]);
            insert(mp[key]);
            return mp[key]->data;
        }
        else return -1;

    }
    void remove(Node* ntr){
        ntr->prev->next=ntr->next;
        ntr->next->prev=ntr->prev;

    }
    void insert(Node* nti){
        nti->prev=tail->prev;
        nti->prev->next=nti;
        nti->next=tail;
        tail->prev=nti;
    }
    
    
    void put(int key, int value) {
        if(mp.count(key)){
                mp[key]->data=value;
                remove(mp[key]);
                insert(mp[key]);
                return;
            }
            
        if(mp.size()<capacity){
            Node* newNode=new Node(key,value);
            mp[key]=newNode;
            insert(mp[key]);
            
        }
        else{
            mp.erase(head->next->key);
            head->next->key=key;
            head->next->data=value;
            mp[key]=head->next;
            remove(mp[key]);
            insert(mp[key]);
            
        }
        return;
    }
};
