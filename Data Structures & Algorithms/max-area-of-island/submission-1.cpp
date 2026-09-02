class Solution {
public:
    int n, m, ans;
    void helper(int i, int j, vector<vector<int>>& grid, int& c){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 0)
            return;
        grid[i][j] = 0;
        c++;
        helper(i-1, j, grid, c);
        helper(i, j-1, grid, c);
        helper(i+1, j, grid, c);
        helper(i, j+1, grid, c);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size(); m = grid[0].size(); ans = 0;
        int c;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    c = 0;
                    helper(i, j, grid, c);
                    ans = max(ans, c);
                }
            }
        }
        return ans;
    }
};
