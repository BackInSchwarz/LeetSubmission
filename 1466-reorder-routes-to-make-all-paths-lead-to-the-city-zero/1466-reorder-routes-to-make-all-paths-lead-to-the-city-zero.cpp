class Solution {
public:
    int ans;
    vector<int> visited;
    
    void dfs(vector<vector<int>> & in, vector<vector<int>> & out, int from){
        
        visited[from] = 1;
        
        for (auto it:out[from]){
            if (!visited[it]){
                // cout<<"a to b changes is "<< from <<" "<< it<<endl;
                ans++;
                dfs(in, out, it);
            }

        }
        
        for (auto it:in[from]){
            if (!visited[it])
                dfs(in, out, it);
        }
        
        return;
        
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<int>> out(n);
        vector<vector<int>> in(n);
        for (auto connection: connections){
            out[connection[0]].push_back(connection[1]); 
            in[connection[1]].push_back(connection[0]); 
        }
        
        ans = 0;
        visited.resize(n, 0);
        
        dfs(in, out, 0);
        
        
        return ans;
    }
};