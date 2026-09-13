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
    ListNode* merge(ListNode* left,ListNode* right){
        ListNode* head=nullptr;
        ListNode* temp1=left;
        ListNode* temp2=right;
        if(temp1->val<temp2->val){
            head=temp1;
            temp1=temp1->next;
        }
        else{
            head=temp2;
            temp2=temp2->next;
        }
        ListNode* temp=head;
        while(temp1!=nullptr && temp2!=nullptr){
            if(temp1->val<temp2->val){
                temp->next=temp1;
                temp1=temp1->next;
                temp=temp->next;

            }
            else{
                temp->next=temp2;
                temp2=temp2->next;
                temp=temp->next;
            }
        }
        if(temp1!=nullptr){
            
            temp->next=temp1;
            temp=temp->next;
        }
        else{
           
            temp->next=temp2;
            temp=temp->next;
        }
        return head;;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* prev=nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        prev->next=nullptr;
        ListNode* left=sortList(head);
        ListNode* right=sortList(slow);
        return merge(left,right);

        
    }
};