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
    ListNode* merge(ListNode* head1,ListNode* head2){
        ListNode* dummy=new ListNode(INT_MIN);
        ListNode* tail=dummy;
        while(head1 && head2){
            if(head1->val<=head2->val){
                tail->next=head1;
                tail=tail->next;
                head1=head1->next;
            }
            else{
                tail->next=head2;
                tail=tail->next;
                head2=head2->next;
            }
        }
        if(head1){
            tail->next=head1;
        }
        if(head2){
            tail->next=head2;
        }
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        ListNode* slow=head;
        ListNode* fast=head->next;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* second=slow->next;
        slow->next=nullptr;
        ListNode* a=sortList(head);
        ListNode* b=sortList(second);
       
        return merge(a,b);

    }
};