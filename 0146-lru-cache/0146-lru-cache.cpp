class LRUCache {
public:
     class Node{
        public:
            int key;
            int value;
            Node* prev;
            Node* next;
            Node(int key,int value){
                this->key=key;
                this->value=value;
            }
        };
        Node* head;
        Node* tail;
        int capacity;
        unordered_map<int,Node*> mp;
        LRUCache(int capacity){
            this->capacity=capacity;
            head=new Node(-1,-1);
            tail=new Node(-1,-1);
            head->next=tail;
            tail->prev=head;

        }
    
    int get(int key) {
        if(mp.find(key)==mp.end()){
            return -1;
        }
        Node* temp=mp[key];
        int ans=temp->value;
        Node* tprev=temp->prev;
        Node* tnext=temp->next;
        tprev->next=tnext;
        tnext->prev=tprev;
        Node* tailprev=tail->prev;
        tailprev->next=temp;
        temp->next=tail;
        tail->prev=temp;
        temp->prev=tailprev;
        return ans;
  
    }
    
    void put(int key, int value) {
        if(mp.find(key)==mp.end()){
            Node* temp=new Node(key,value);
            Node* tailprev=tail->prev;
            tailprev->next=temp;
            temp->next=tail;
            tail->prev=temp;
            temp->prev=tailprev;
            mp[key]=temp;
        
        }
        else{
            Node* temp=mp[key];
            Node* tprev=temp->prev;
            Node* tnext=temp->next;
            tprev->next=tnext;
            tnext->prev=tprev;
            temp->value=value;
            Node* tailprev=tail->prev;
            tailprev->next=temp;
            temp->next=tail;
            tail->prev=temp;
            temp->prev=tailprev;
        }
        int curr=mp.size();
        if(curr>capacity){
            Node* temp=head->next;
            Node* ahead=temp->next;
            head->next=ahead;
            ahead->prev=head;
            int remkey=temp->key;
            mp.erase(remkey);
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */