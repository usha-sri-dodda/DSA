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
    pair<ListNode*, ListNode*> reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return {prev, head};   // new head , new tail
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head||!head->next||k==0)  return head;
        ListNode* temp=head;
        int n=0;
        while(temp){
            n++;
            temp=temp->next;
        }
        k=k%n;
        if(k==0)    return head;
        temp=head;
        for(int i=0;i<n-1-k;i++){
            temp=temp->next;
        }
        ListNode* curr=temp->next;
        temp->next=nullptr;
        ListNode* currH=curr;
        while(curr->next) curr=curr->next;
        curr->next=head;
        return currH;
    }
};
