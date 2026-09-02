struct TrieNode{
    vector<TrieNode*> child;
    bool isWord;

    TrieNode(){
        child.resize(26, NULL);
        isWord = false;
    }
};
class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* temp = root;
        for(auto w: word){
            int i = w - 'a';
            if(!temp->child[i])
                temp->child[i] = new TrieNode();
            temp = temp->child[i];
        }
        temp->isWord = true;
    }
    
    bool search(string word) {
        TrieNode* temp = root;
        for(auto w: word){
            int i = w - 'a';
            if(!temp->child[i])
                return false;
            temp = temp->child[i];
        }
        return temp->isWord;
    }
    
    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for(auto w: prefix){
            int i = w - 'a';
            if(!temp->child[i])
                return false;
            temp = temp->child[i];
        }
        return true;
    }
};
