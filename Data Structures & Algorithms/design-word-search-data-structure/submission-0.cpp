class TrieNode {
public:
    vector<TrieNode*> child;
    bool isWord;
    
    TrieNode(){
        isWord = false;
        child.resize(26, NULL);
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* temp = root;
        for(auto w: word){
            int i = w - 'a';
            if(!temp->child[i])
                temp->child[i] = new TrieNode();
            temp = temp->child[i];
        }
        temp->isWord = true;
    }
    
    bool helper(string word, int i, TrieNode* t, bool isWord) {
        if(i == word.size())
            return isWord;
        if(word[i] != '.'){
            if(!t->child[word[i]-'a'])
                return false;
            t = t->child[word[i]-'a'];
            return helper(word, i+1, t, t->isWord);
        }
        for(int j=0; j<26; j++){
            if(t->child[j] && helper(word, i+1, t->child[j], t->child[j]->isWord))
                return true;
        }
        return false;
    }
    bool search(string word){
        TrieNode* t = root;
        return helper(word, 0, t, false);
    }
};
