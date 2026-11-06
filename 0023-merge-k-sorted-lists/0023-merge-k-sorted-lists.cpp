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
    ListNode* convert(vector<int> &arr){
        if(arr.size()==0) return nullptr;
        ListNode* head=new ListNode(arr[0]);
        ListNode* temp=head;
        int i=1;
        while(i<arr.size()){
            ListNode* newnode=new ListNode(arr[i]);
            temp->next=newnode;
            temp=temp->next;
            i++;
        }
        return head;

    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;
        for(int i=0;i<lists.size();i++){
            ListNode* temp=lists[i];
            while(temp!=nullptr){
                arr.push_back(temp->val);
                temp=temp->next;     
            }
        }
        sort(arr.begin(),arr.end());
        ListNode* head=convert(arr);
        return head;
    }
};