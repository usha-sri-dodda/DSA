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

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode dummy(0);
        ListNode* prevGroupTail = &dummy;
        ListNode* curr = head;

        while (curr) {
            ListNode* temp = curr;
            int cnt = 0;

            while (temp && cnt < k) {
                temp = temp->next;
                cnt++;
            }

            if (cnt < k) {
                prevGroupTail->next = curr;
                break;
            }

            ListNode* nextGroupHead = temp;

            temp = curr;
            for (int i = 1; i < k; i++) temp = temp->next;
            temp->next = nullptr;

            auto res = reverse(curr);

            prevGroupTail->next = res.first;
            res.second->next = nextGroupHead;

            prevGroupTail = res.second;
            curr = nextGroupHead;
        }

        return dummy.next;
    }
};
