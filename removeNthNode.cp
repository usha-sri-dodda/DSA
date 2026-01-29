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
     ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int k=0;
        ListNode* temp=head;
        while(temp){
            temp=temp->next;
            k++;
        }
        temp=head;
        int i=0;
        if(k==n)   { 
            ListNode* temp=head;
            head=head->next; 
            delete temp;
            return head; }
        while(temp){
            if(i==k-n-1){
                ListNode* tem=temp->next;
                temp->next=tem->next;
                delete tem;
                return head;
            }
            temp=temp->next;
            i++;
        }
        
       
        return head;
        
    }
};
