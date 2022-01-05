class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int N = edges.size() + 1;
        vector<int> count(N+1, 0);
        for (auto edge: edges){
            count[edge[0]]++;
            count[edge[1]]++;
        }
        
        for (int i = 1; i<=N; i++){
            if ( count[i] == N-1) return i;
        }
        
        return -1;
    }
};