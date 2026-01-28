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
        if(!head||!head->next)  return head;
        ListNode* temp=head;
        ListNode* prev=nullptr;
        ListNode* back=nullptr;
        while(temp){
            back=temp->next;
            temp->next=prev;
            prev=temp;
            temp=back;
        }
        return prev;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head;
        if(!head||!head->next)  return true;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* temp1=reverse(slow);
        ListNode* temp2=head;
        while(temp1){
            if(temp1->val!=temp2->val)  return false;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;
    }
};
