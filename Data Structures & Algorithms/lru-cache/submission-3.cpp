struct Node{
    int key, val;
    Node *next, *pre;
    Node(int k, int v){
        key = k;
        val = v;
        pre = NULL;
        next = NULL;
    }
};
class LRUCache {
public:
    Node *start, *end;
    unordered_map<int, Node*> mp;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        start = new Node(0, 0);
        end = new Node(0, 0);
        start->next = end;
        end->pre = start;
    }

    void moveToFirst(Node* temp){
        Node *nxt = temp->next, *pre = temp->pre;
        pre->next = nxt;
        nxt->pre = pre;
        end->pre->next = temp;
        temp->pre = end->pre;
        temp->next = end;
        end->pre = temp;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        moveToFirst(mp[key]);
        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            moveToFirst(mp[key]);
            mp[key]->val = value;
        }
        else{
            Node *temp = new Node(key, value);
            mp[key] = temp;
            end->pre->next = temp;
            temp->pre = end->pre;
            end->pre = temp;
            temp->next = end;
            if(mp.size() > cap){
                mp.erase(start->next->key);
                start->next = start->next->next;
                start->next->pre = start;
            }
        }
    }
};
