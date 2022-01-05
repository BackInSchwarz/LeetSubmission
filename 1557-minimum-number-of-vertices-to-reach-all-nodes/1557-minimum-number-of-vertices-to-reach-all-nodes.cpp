class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> incoming(n, 0);
        
        for (auto & edge:edges){
            incoming[edge[1]]++;
        }
        
        vector<int> ans;
        
        for (int i = 0; i < n; i++){
            if ( incoming[i] == 0)
                ans.push_back(i);
        }
        
        return ans;
    }
};