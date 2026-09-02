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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head, *pre;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        pre = slow;
        slow = slow->next;
        pre->next = NULL;
        stack<ListNode*> st;
        while(slow){
            st.push(slow);
            slow = slow->next;
        }
        slow = head;
        while(!st.empty()){
            pre = slow->next;
            slow->next = st.top();
            st.top()->next = pre;
            st.pop();
            slow = pre;
        }
    }
};
