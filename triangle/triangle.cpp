class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int ht= triangle.size();
        
        for (int i = 1;i<ht;i++){
            for (int j = 0;j<=i;j++){
                triangle[i][j] = min(triangle[i-1][min(i-1,j)], triangle[i-1][max(0, j-1)]) + triangle[i][j] ;
            }
        }
        
        int ans = INT_MAX;
        for (int j = 0;j<ht;j++){
            ans= min(ans, triangle[ht-1][j]);
        }
        
        return ans;
    }
};