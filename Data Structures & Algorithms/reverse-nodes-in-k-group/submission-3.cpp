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
    ListNode* reverseKNodes(stack<ListNode*>& st){
        ListNode *head = st.top(), *temp = head;
        st.pop();
        while(!st.empty()){
            temp->next = st.top();  st.pop();
            temp = temp->next;
        }
        tail = temp;
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> st;
        ListNode *h = head, *nt = NULL;
        while(h){
            for(int i=0; i<k && h; i++){
                st.push(h);
                h = h->next;
            }
            if(st.size() < k)
                break;
            if(!nt)
                head = reverseKNodes(st);
            else
                nt->next = reverseKNodes(st);
            nt = tail;
            nt->next = h;
        }
        return head;
    }
};
