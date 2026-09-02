class Solution {
public:
    void helper(int i, int j, vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() || grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        helper(i-1, j, grid);
        helper(i, j-1, grid);
        helper(i+1, j, grid);
        helper(i, j+1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == '1'){
                    ans++;
                    helper(i, j, grid);
                }
            }
        }
        return ans;
    }
};
