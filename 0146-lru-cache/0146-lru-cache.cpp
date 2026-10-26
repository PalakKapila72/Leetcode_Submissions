
class LRUCache {
public:
    class Node{
        public:
        int key;
        int val;
        Node*next;
        Node*prev;
        Node(int key,int val){
            this->key=key;
            this->val=val;
            next=nullptr;
            prev=nullptr;
        }
    };
    unordered_map<int,Node*> mpp;
    int capacity;
    Node*head;
    Node*tail; 
    void deletenode(Node* node){
        Node* afternode=node->next;
        Node* prevnode=node->prev;
        afternode->prev=prevnode;
        prevnode->next=afternode;   
    }
    void insertafterhead(Node* node){
        Node* currafterhead=head->next;
        head->next=node;
        node->prev=head;
        node->next=currafterhead;
        currafterhead->prev=node;
    }
    LRUCache(int capacity) {
        this->capacity=capacity;
        head=new Node(-1,-1);
        tail=new Node(-1,-1);
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node=mpp[key];
        deletenode(node);
        insertafterhead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            node->val=value;
            deletenode(node);
            insertafterhead(node);
        }
        else{
            if(mpp.size()==capacity){
                Node* node=tail->prev;
                mpp.erase(node->key);
                deletenode(node);
            }
            Node* node=new Node(key,value);
            mpp[key]=node;
            insertafterhead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */