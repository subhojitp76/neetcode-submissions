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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *temp = l1, *pre;
        int carry = 0;
        while(temp && l2){
            temp->val += l2->val + carry;
            carry = temp->val>9? 1: 0;
            temp->val = temp->val%10;
            pre = temp;
            temp = temp->next;
            l2 = l2->next;
        }
        if(l2){
            pre->next = l2;
            while(l2 && carry){
                l2->val += carry;
                carry = l2->val>9? 1: 0;
                l2->val = l2->val%10;
                pre = l2;
                l2 = l2->next;
            }
        }
        else{
            while(temp && carry){
                temp->val += carry;
                carry = temp->val>9? 1: 0;
                temp->val = temp->val%10;
                pre = temp;
                temp = temp->next;
            }
        }
        if(carry){
            pre->next = new ListNode(carry);
        }
        return l1;
    }
};
