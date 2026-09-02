class Solution {
public:
    int helper(int i, int j){
        if(i <= 2)
            return j<=2? 0: j<=5? 1: 2;
        else if(i <= 5)
            return j<=2? 3: j<=5? 4: 5;
        else
            return j<=2? 6: j<=5? 7: 8;
        
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> mr, mc, sec;
        int t;
        for(int i=0; i<9; i++){
            for(int j=0;j<9; j++){
                if(board[i][j] == '.')
                    continue;
                t = helper(i, j);
                if(mr[i].count(board[i][j]) || mc[j].count(board[i][j]) || sec[t].count(board[i][j]))
                    return false;
                mr[i].insert(board[i][j]);
                mc[j].insert(board[i][j]);
                sec[t].insert(board[i][j]);
            }
        }
        return true;
    }
};
