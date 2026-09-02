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
    ListNode* tail;
    ListNode* reverseGroup(stack<ListNode*>& st){
        ListNode* head = st.top(), *pre = head;
        st.pop();
        while(!st.empty()){
            pre->next = st.top();
            st.pop();
            pre = pre->next;
            tail = pre;
        }
        tail->next = NULL;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *h = head, *nt, *temp;
        head = NULL;
        stack<ListNode*> st;
        while(h){
            for(int i=0; i<k && h; i++){
                st.push(h);
                h = h->next;
            }
            if(st.size() < k)
                break;
            temp = reverseGroup(st);
            if(!head)
                head = temp;
            else
                nt->next = temp;
            nt = tail;
            nt->next = h;
        }
        return head;
    }
};
