class Solution {
public:
    int m, n;
    bool helper(vector<vector<char>>& board, string& word, int i, int j, int k){
        if(k == word.size())
            return true;
        if(i==m || i<0 || j==n || j<0 || board[i][j]!=word[k] || board[i][j]=='0')
            return false;
        board[i][j] = '0';
        if(helper(board, word, i+1, j, k+1) || helper(board, word, i-1, j, k+1) || helper(board, word, i, j+1, k+1) || helper(board, word, i, j-1, k+1))
            return true;
        board[i][j] = word[k];
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(helper(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
};
