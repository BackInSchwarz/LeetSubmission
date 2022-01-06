class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> in(n+1);
        vector<vector<int>> out(n+1);
        
        for (auto & t:trust){
            in[t[1]].push_back(t[0]);
            out[t[0]].push_back(t[1]);
        }
        
        for ( int i = 1; i <= n; i++){
            if ( out[i].size() == 0 && in[i].size() == (n-1))
                return i;
        }
        
        return -1;
    }
};