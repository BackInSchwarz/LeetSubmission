class Solution {
public:
    
    int curArea;
    
    
    void dfs(vector<vector<int>>& grid, int i, int j){
        
        if(i<0 || i>(grid.size()-1)) return;
        if(j<0 || j>(grid[0].size() - 1)) return;
        
        if (grid[i][j] == 1){
            grid[i][j] = -1;
            curArea++;
            
            dfs(grid, i+1, j+0);
            dfs(grid, i-1, j-0);
            dfs(grid, i+0, j+1);
            dfs(grid, i-0, j-1);
        }
        

        
        return;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxArea = 0;
        curArea = 0;
        
        
        int r = grid.size();
        int c = grid[0].size();
        
        for ( int i = 0; i < r; i++){
            for ( int j = 0; j<c ; j++){
                if ( grid[i][j] == 1){
                    curArea = 0;
                    dfs(grid, i, j);
                    maxArea = max( maxArea, curArea);
                }
            }
        }
        
        return maxArea;
        
    }
};

