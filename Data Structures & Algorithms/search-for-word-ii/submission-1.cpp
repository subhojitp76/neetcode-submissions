struct TrieNode{
    vector<TrieNode*> child;
    bool isWord;\
    TrieNode(){
        child.resize(26, NULL);
        isWord = false;
    }
};
class Solution {
public:
    int m, n;
    void addWord(TrieNode* root, string word){
        for(auto c: word){
            if(!root->child[c-'a'])
                root->child[c-'a'] = new TrieNode();
            root = root->child[c-'a'];
        }
        root->isWord = true;
    }
    void helper(vector<vector<char>>& board, vector<string>& ans, TrieNode* root, int i, int j, string s){
        // cout << i << " " << j << endl;
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]=='-' || !root->child[board[i][j]-'a'])
            return;
        s += board[i][j];
        int ch = board[i][j] - 'a';
        root = root->child[ch];
        if(root->isWord){
            // cout << "hit------>" << s << endl;
            root->isWord = false;
            ans.push_back(s);
        }
        board[i][j] = '-';
        helper(board, ans, root, i+1, j, s);
        helper(board, ans, root, i, j+1, s);
        helper(board, ans, root, i-1, j, s);
        helper(board, ans, root, i, j-1, s);
        board[i][j] = 'a' + ch;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();   n = board[0].size();
        TrieNode* root = new TrieNode();
        for(auto word: words)
            addWord(root, word);
        vector<string> ans;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                helper(board, ans, root, i, j, "");
        return ans;
    }
};
