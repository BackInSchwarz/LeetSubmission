class Solution {
public:
    void dfs(vector<vector<int>>& grid, int row, int col, int originalcolor){
        if ((row<0)||(row>=grid.size())) return;
        if ((col<0)||(col>=grid[0].size())) return;
        
        if (grid[row][col]==1001) return;
        if (grid[row][col]!=originalcolor) return;
        
        grid[row][col] = 1001;
        
        dfs(grid, row+1, col, originalcolor);
        dfs(grid, row-1, col, originalcolor);
        dfs(grid, row, col+1, originalcolor);
        dfs(grid, row, col-1, originalcolor);
        
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int originalcolor = grid[row][col];
        dfs(grid, row, col, originalcolor);
        
        for (int i=1;i<grid.size()-1;i++){
            for (int j=1;j<grid[0].size()-1;j++){
                // cout<<grid[i][j];
                if (grid[i][j]==1001){
                    bool inside = (grid[i-1][j]==1001||grid[i-1][j]==originalcolor) &&
                                  (grid[i+1][j]==1001||grid[i+1][j]==originalcolor) &&
                                  (grid[i][j+1]==1001||grid[i][j+1]==originalcolor) &&
                                  (grid[i][j-1]==1001||grid[i][j-1]==originalcolor);
                    if (inside ==true) grid[i][j]=originalcolor;
                }
            }
            // cout<<endl;
        }
 
        for (int i=0;i<grid.size();i++){
            for (int j=0;j<grid[0].size();j++){
                // cout<<grid[i][j];
                if (grid[i][j]==1001){
                    grid[i][j]=color;
                }
            }
            // cout<<endl;
        }
        
        
        return grid; 
    }
};