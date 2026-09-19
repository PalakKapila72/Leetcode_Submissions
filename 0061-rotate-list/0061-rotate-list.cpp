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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* temp=head;
        int length=0;
        while(temp!=nullptr){
            temp=temp->next;
            length++;
        }
        k=k%length;
        if(k==0){
            return head;
        }
        temp=head;
        int cnt=0;
        int n=length-k;
        while(cnt<n-1){
            temp=temp->next;
            cnt++;
        }
        ListNode* temp2=temp->next;
        temp->next=nullptr;
        ListNode* curr=temp2;
        while(curr->next!=nullptr){
            curr=curr->next;
        }
        curr->next=head;
        head=temp2;
        return head;

    }
};