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
        ListNode *pre=NULL, *cur = head, *end = head;
        while(--n)
            end = end->next;
        if(!end->next)
            return head->next;
        while(end->next){
            pre = cur;
            cur = cur->next;
            end = end->next;
        }
        pre->next = cur->next;
        return head;
    }
};
