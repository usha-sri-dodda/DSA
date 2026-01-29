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
     ListNode* reverse(ListNode* head) {
        if(!head||!head->next) return  head;
        ListNode* next=nullptr;
        ListNode* temp=head;
        ListNode* prev=nullptr;
        while(temp){
           next=temp->next;
           temp->next=prev;
           prev=temp;
           temp=next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        
        ListNode* n1=l1;
        ListNode* n2=l2;
        ListNode* res=new ListNode(-1);
        ListNode* resH=res;
        int carry=0,sum=0;
        while(n1||n2||carry){
            sum=carry;
            if(n1){
                sum+=n1->val;
                n1=n1->next;
            }
            if(n2){
                sum+=n2->val;
                n2=n2->next;
            }
            res->next=new ListNode(sum%10);
            res=res->next;
            carry=sum/10;
        }
        if(carry)   res->next=new ListNode(carry);
        return resH->next;
    }
};
