class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix.size();
        
        for(int i = 1;i<r;i++){
            for (int j = 1;j<c-1;j++){
                matrix[i][j] = min(matrix[i-1][j-1], min(matrix[i-1][j], matrix[i-1][j+1])) + matrix[i][j];
            }
            
            if (c>1){
                matrix[i][0] = matrix[i][0] + min(matrix[i-1][0], matrix[i-1][1]);
                matrix[i][c-1] = matrix[i][c-1] + min(matrix[i-1][c-1], matrix[i-1][c-2]);
            }else{
                matrix[i][0] += matrix[i-1][0];
            }

        }
        
        int ans=INT_MAX;
        for (int i=0;i<c;i++){
            ans = min(ans, matrix[r-1][i]);
        }
        
        return ans;
    }
};