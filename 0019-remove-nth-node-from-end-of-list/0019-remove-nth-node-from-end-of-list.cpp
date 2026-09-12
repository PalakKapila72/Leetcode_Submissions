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
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=nullptr){
            ListNode* next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr || head->next==nullptr){
            if(n==1){
                return nullptr;
            }
            return head;
        }
        head=reverse(head);
        int count=1;
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(count!=n && temp!=nullptr){
           prev=temp;
            count++;
            temp=temp->next;
        }
        if(prev==nullptr){
            head=temp->next;
        }
        else{
        prev->next=temp->next;}
        head=reverse(head);
        return head;



    }
};