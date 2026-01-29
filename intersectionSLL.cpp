/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l=headA;
        ListNode* r=headB;
        while(l!=r){
            if(l==nullptr)    l=headB;
            else    l=l->next;
            if(r==nullptr)    r=headA;
            else    r=r->next;
        }
        return l;
    }
};
