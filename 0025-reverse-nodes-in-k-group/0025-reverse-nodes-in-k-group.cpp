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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* prevgroup=dummy;
        while(true){
            ListNode* kth=prevgroup;
            for(int i=0;i<k;i++){
                kth=kth->next;
                if(kth==nullptr){
                    return dummy->next;
                }
            }
            ListNode* nextgroup=kth->next;
            ListNode* prev=nextgroup;
            ListNode*curr=prevgroup->next;
            while(curr!=nextgroup){
                ListNode* next=curr->next;
                curr->next=prev;
                prev=curr;
                curr=next;
            }
            ListNode* oldstart=prevgroup->next;
            prevgroup->next=kth;
            prevgroup=oldstart;


        }
        
    }
};