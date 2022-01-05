class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> f(2000, 0);
        
        for (int i = 0; i < f.size(); i++){
            f[i] = i;
        }
        vector<int> res;
        
        for (vector<int> edge:edges){
            int n1 = edge[0];
            int n2 = edge[1];
            while(n1 != f[n1]) n1 = f[n1];
            while(n2 != f[n2]) n2 = f[n2];
            if ( n1 == n2){
                return edge;
            }else{
                f[n1] = n2;
            }

        }
        
        return {-1};
    }
};