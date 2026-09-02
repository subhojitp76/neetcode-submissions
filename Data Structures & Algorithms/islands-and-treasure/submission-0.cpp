class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<vector<int>> pos;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 0){
                    pos.push({i-1, j, 1});
                    pos.push({i+1, j, 1});
                    pos.push({i, j-1, 1});
                    pos.push({i, j+1, 1});
                }
            }
        }
        while(!pos.empty()){
            auto t = pos.front();   pos.pop();
            if(t[0]<0 || t[0]>=n || t[1]<0 || t[1]>=m
             || grid[t[0]][t[1]]==-1 || grid[t[0]][t[1]]==0 || grid[t[0]][t[1]]<=t[2])
                continue;
            grid[t[0]][t[1]] = t[2];
            pos.push({t[0]-1, t[1], t[2]+1});
            pos.push({t[0]+1, t[1], t[2]+1});
            pos.push({t[0], t[1]-1, t[2]+1});
            pos.push({t[0], t[1]+1, t[2]+1});
        }
    }
};
