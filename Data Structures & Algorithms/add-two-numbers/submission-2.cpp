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
    ListNode* addTwoNumbers(ListNode* n1, ListNode* n2) {
        int carry = 0, t;
        ListNode *l1 = n1, *l2 = n2, *pre;
        while(l1 && l2){
            t = l1->val + l2->val + carry;
            carry = t / 10;
            l2->val = t % 10;
            pre = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l2){
            t = l2->val + carry;
            carry = t / 10;
            l2->val = t % 10;
            pre = l2;
            l2 = l2->next;
        }
        while(l1){
            t = l1->val + carry;
            carry = t / 10;
            pre->next = new ListNode(t % 10);
            pre = pre->next;
            l1 = l1->next;
        }
        if(carry)
            pre->next = new ListNode(carry);
        return n2;
    }
};
