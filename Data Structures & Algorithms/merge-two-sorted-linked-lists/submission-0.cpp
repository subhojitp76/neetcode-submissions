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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 || !list2)
            return list1? list1 : list2;
        if(list1->val > list2->val)
            swap(list1, list2);
        ListNode *head = list1, *temp;
        while(head->next){
            if(head->next->val > list2->val){
                temp = head->next;
                head->next = list2;
                list2 = temp;
            }
            head = head->next;
        }
        if(list2)
            head->next = list2;
        return list1;
    }
};
