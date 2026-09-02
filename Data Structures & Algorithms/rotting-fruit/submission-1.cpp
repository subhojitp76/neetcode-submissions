class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size(), ans = 0, s = 0;
        queue<vector<int>> q1, q2;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q1.push({i-1, j});
                    q1.push({i+1, j});
                    q1.push({i, j-1});
                    q1.push({i, j+1});
                }
            }
        }
        while(!q1.empty()){
            auto t = q1.front();    q1.pop();
            if(t[0]>=0 && t[0]<n && t[1]>=0 && t[1]<m && grid[t[0]][t[1]]==1){
                grid[t[0]][t[1]] = 2;
                q2.push({t[0]-1, t[1]});
                q2.push({t[0]+1, t[1]});
                q2.push({t[0], t[1]-1});
                q2.push({t[0], t[1]+1});
            }
            if(q1.empty()){
                ans++;
                s = 1;
                swap(q1, q2);
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        return ans - s;
    }
};
