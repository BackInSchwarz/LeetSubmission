class Solution {
public:
    
    bool isValid(int i, int j, int r, int c){
        if (i<0||i>(r-1)) return false;
        if (j<0||j>(c-1)) return false;
        
        return true;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        
        
        int ans=0;
        
        for (int i = 0; i<r;i++){
            for  (int j = 0; j<c ;j++){
                // cout<<" i: "<< i << " j: "<< j <<endl;
                // cout<< "cur Ans is :"<<ans<<endl;
                if (grid[i][j]==0) continue;
                
                //left [i-1][j]
                if (isValid(i-1, j, r, c)){
                    if(grid[i-1][j]==0)
                        ans++;
                }else{
                    ans++;
                }
                    
                //right [i+1][j]
                if (isValid(i+1, j, r, c)){
                    if(grid[i+1][j]==0)
                        ans++;
                }else{
                    ans++;
                }
                //up [i][j-1]
                if (isValid(i, j-1, r, c)){
                    if(grid[i][j-1]==0)
                        ans++;
                }else{
                    ans++;
                }
                //down [i][j+1]
                if (isValid(i, j+1, r, c)){
                    if(grid[i][j+1]==0)
                        ans++;
                }else{
                    ans++;
                }
                
            }
        }
        
        return ans;
    }
};