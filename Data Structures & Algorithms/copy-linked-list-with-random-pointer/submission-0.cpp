/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node* h = head;
        while(h){
            Node* temp = new Node(h->val);
            mp[h] = temp;
            h = h->next;
        }
        h = head;
        while(h){
            mp[h]->next = mp[h->next];
            mp[h]->random = mp[h->random];
            h = h->next;
        }
        return mp[head];
    }
};
