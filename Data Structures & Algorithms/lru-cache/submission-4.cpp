struct Node{
    int key, value;
    Node *pre, *nxt;
    Node(int k, int v){
        key = k;
        value = v;
        pre = NULL;
        nxt = NULL;
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
        start->nxt = end;
        end->pre = start;
    }

    void moveToFirst(Node* temp){
        Node *pre = temp->pre, *nxt = temp->nxt;
        pre->nxt = nxt;
        nxt->pre = pre;
        end->pre->nxt = temp;
        temp->pre = end->pre;
        temp->nxt = end;
        end->pre = temp;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        Node *temp = mp[key];
        moveToFirst(temp);
        return temp->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            moveToFirst(mp[key]);
            mp[key]->value = value;
        }
        else{
            Node *temp = new Node(key, value);
            mp[key] = temp;
            temp->pre = end->pre;
            temp->pre->nxt = temp;
            temp->nxt = end;
            end->pre = temp;
            if(mp.size() > cap){
                mp.erase(start->nxt->key);
                start->nxt = start->nxt->nxt;
                start->nxt->pre = start;
            }
        }
    }
};
