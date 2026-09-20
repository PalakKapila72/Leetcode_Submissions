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
    void insertcopynode(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            Node* copynode=new Node(temp->val);
            copynode->next=temp->next;
            temp->next=copynode;
            temp=temp->next->next;
        }
        
    }
    void connectrandom(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            Node* copynode=temp->next;
            if(temp->random){
            copynode->random=temp->random->next;}
            else{
                copynode->random=nullptr;
            }
            temp=temp->next->next;
        }

    }
    Node* connectnextpointers(Node* head){
        Node* dummy=new Node(-1);
        Node* res=dummy;
        Node* temp=head;
        while(temp!=nullptr){
            Node* copynode=temp->next;
            res->next=copynode;
            temp->next=temp->next->next;
            res=res->next;
            temp=temp->next;
        }
        return dummy->next;
    }
    Node* copyRandomList(Node* head) {
        insertcopynode(head);
        connectrandom(head);
        head=connectnextpointers(head);
        return head;
        
        
    }
};