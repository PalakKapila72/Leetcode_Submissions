class LFUCache {
public:
    class Node{
        public:
        int key,value,freq;
        Node* prev;
        Node* next;
        Node(int key,int value){
            this->key=key;
            this->value=value;
            freq=1;
            next=nullptr;
            prev=nullptr;
        }
    };
    int capacity,minfreq;
    unordered_map<int,list<Node*>> freqlist;
    unordered_map<int,Node*> mpp;
    LFUCache(int capacity) {
        this->capacity=capacity;
        minfreq=0;
    }
    void removenode(Node* node){
        int freq=node->freq;
        freqlist[freq].remove(node);
    }
    void addnode(Node* node){
        int freq=node->freq;
        freqlist[freq].push_front(node);
    }
    void updatefreq(Node* node){
        int oldfreq=node->freq;
        removenode(node);
        if(freqlist[oldfreq].empty()){
            freqlist.erase(oldfreq);
        
        if(minfreq==oldfreq){
            minfreq++;
        }
        }
        node->freq++;
        addnode(node);
    }
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        Node* node=mpp[key];
        updatefreq(node);
        return node->value;
    }
    
    void put(int key, int value) {
        if(capacity==0) return;
        if(mpp.find(key)!=mpp.end()){
            Node* node=mpp[key];
            updatefreq(node);
            node->value=value;
            return;
        }
        if(mpp.size()==capacity){
            Node* lfu=freqlist[minfreq].back();
            freqlist[minfreq].pop_back();
            mpp.erase(lfu->key);
            delete lfu;
            if(freqlist[minfreq].empty()){
                freqlist.erase(minfreq);
            }
        }
        Node* node=new Node(key,value);
        mpp[key]=node;
        freqlist[1].push_front(node);
        minfreq=1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */