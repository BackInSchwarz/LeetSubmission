class Solution {
public:
    
    void dfs( vector<vector<int>>& isConnected, int i){
        
        vector<int> next;
        for (int j=0;j<isConnected[i].size(); j++){
            if ( isConnected[i][j] == -1){
                return;
            }else{

                if (isConnected[i][j] == 1) {
                    next.push_back(j);
                }
                isConnected[i][j] = -1;
            }

        }
        
        for (auto j: next){
            dfs(isConnected, j);
        }
        
        return;
        
    }
    
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int ans = 0;
        
        for ( int i = 0; i<isConnected.size(); i++){
            // cout<< "main i :" << i<<endl;
            if (isConnected[i][0] != -1){
                ans++;
                dfs(isConnected, i);
            }
        }
        
        return ans;
    }
};