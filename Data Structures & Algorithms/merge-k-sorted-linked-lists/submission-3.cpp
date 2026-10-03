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
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2){
        if(!l1 | !l2)
            return l1? l1: l2;
        if(l1->val > l2->val)
            swap(l1, l2);
        ListNode *head = l1, *temp;
        while(head->next && l2){
            if(l2->val < head->next->val){
                temp = head->next;
                head->next = l2;
                l2 = temp;
            }
            head = head->next;
        }
        if(!head->next)
            head->next = l2;
        return l1;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(!lists.size())
            return NULL;
        int k = lists.size();
        while (k > 1) {
            for (int i = 0; i < k/2; i++) {
                lists[i] = mergeTwoList(lists[i], lists[k-i-1]);
            }
            k = (k+1)/2;
        }
        return lists[0];
    }
};
