class Solution {
public:
    int ans;
    void walkRobot(vector<vector<int>> grid, int stepsWalked, int& stepMax, int i, int j){
        if (i<0||(i>grid.size()-1)) return;
        if (j<0||(j>grid[0].size()-1)) return;
        // cout<<"Steps walked is "<<stepsWalked<<endl;
        if (grid[i][j]==2){
            // cout<<"target reached :"<<"Steps walked is "<<stepsWalked<<endl;
            if (stepsWalked>=stepMax){
                
                ans+=1;
                // return;
            }
            return;
        }
        if (grid[i][j]=='X'||grid[i][j]==-1) return;
        
        grid[i][j]='X';
        
        walkRobot(grid, stepsWalked+1, stepMax, i+1,j);
        walkRobot(grid, stepsWalked+1, stepMax, i-1,j);
        walkRobot(grid, stepsWalked+1, stepMax, i,j+1);
        walkRobot(grid, stepsWalked+1, stepMax, i,j-1);
            
            
        return;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int stepMax = 1;
        int i_start = 0;
        int j_start = 0;
        for (int i = 0;i<r;i++){
            for (int j= 0;j<c;j++){
                if (grid[i][j]==0) stepMax+=1;  
                if (grid[i][j]==1){
                    i_start = i;
                    j_start = j;
                }
            }
        }
        cout<<stepMax<<endl;
        
        ans = 0;
        walkRobot(grid, 0, stepMax, i_start, j_start);
        
        return ans;
    }
};