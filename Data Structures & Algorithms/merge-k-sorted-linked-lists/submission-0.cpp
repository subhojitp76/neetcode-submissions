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
    ListNode* merger2Lists(ListNode* head, ListNode* l2){
        if(!head || !l2)
            return !head? l2: head;
        if(l2->val < head->val)
            swap(head, l2);
        ListNode* temp = head, *t;
        while(temp->next && l2){
            if(temp->next->val <= l2->val)
                temp = temp->next;
            else{
                t = temp->next;
                temp->next = l2;
                l2 = t;
            }
        }
        if(!temp->next)
            temp->next = l2;
        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        for(int i=1; i<lists.size(); i++){
            lists[0] = merger2Lists(lists[0], lists[i]);
        }
        return lists[0];
    }
};
