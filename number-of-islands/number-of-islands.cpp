class Solution {
public:
    void dfs(vector<vector<char>>& grid, int curR, int curC){
        int r = grid.size();
        int c = grid[0].size();
        if ((curR<0)||(curR>=r)) return;
        if ((curC<0)||(curC>=c)) return;
        if (grid[curR][curC]=='X') return;
        if (grid[curR][curC]=='0') return;
        
        grid[curR][curC]='X';
        
        dfs(grid, curR+1,curC);
        dfs(grid, curR,curC+1);
        dfs(grid, curR-1,curC);
        dfs(grid, curR,curC-1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int ans = 0;
        for (int i = 0; i<r;i++){
            for (int j = 0;j<c;j++){
                if (grid[i][j]=='X') continue;
                if (grid[i][j]=='0') continue;
                if (grid[i][j]=='1'){
                    
                    ans+=1;
                    dfs(grid, i,j);
                    // grid[i][j]="X";
                }
            }
        }
        
        return ans;
    }
};