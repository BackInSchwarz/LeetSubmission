class Solution {
public:
    
    int getSum(vector<vector<int>>& mat, int i, int j){
        if (i<0 || j<0) return 0;
        
        int r = mat.size();
        int c = mat[0].size();
        
        if (i>=r) i = r - 1;
        if (j>=c) j = c - 1;
        
        return mat[i][j];
    }
    
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        //integral image or prefix sum. 
        int r = mat.size();
        int c = mat[0].size();
        
        for (int i = 1; i<c;i++){
            mat[0][i] +=mat[0][i-1];
        }
        
        for (int i = 1; i<r;i++){
            mat[i][0] +=mat[i-1][0];
        }
        
        for (int i = 1;i<r;i++){
            for (int j = 1;j<c;j++){
                mat[i][j] = mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1] + mat[i][j];
            }
        }
        
        // if ((k >(r/2)) and (k>(c/2))) return mat;
        vector<vector<int>> ans(r, vector<int>(c, 0));
        for (int i = 0;i<r;i++){
            for (int j = 0;j<c;j++){
                ans[i][j] =   getSum(mat, i-k-1, j-k-1) 
                            + getSum(mat, i+k,   j+k) 
                            - getSum(mat, i+k,   j-k-1) 
                            - getSum(mat, i-k-1, j+k);
            }
        }
        
        
        return ans;
        
    }
};