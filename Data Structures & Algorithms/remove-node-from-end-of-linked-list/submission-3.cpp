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
        ListNode *cur = head, *pre = NULL, *nth = head;
        while(n > 1){
            nth = nth->next;
            n--;
        }
        if(!nth->next)
            return head->next;
        while(nth->next){
            pre = cur;
            cur = cur->next;
            nth = nth->next;
        }
        pre->next = cur->next;
        return head;
    }
};
