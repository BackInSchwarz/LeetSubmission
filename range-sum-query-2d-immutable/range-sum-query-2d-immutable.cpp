class NumMatrix {
public:
    vector<vector<int>> IM;
    
    NumMatrix(vector<vector<int>>& matrix) {
        IM = matrix;
        
        int r = IM.size();
        int c = IM[0].size();
        
        for (int i = 1; i<r;i++){
            IM[i][0] += IM[i-1][0];
        }
        
        for (int j = 1; j<c;j++){
            IM[0][j] += IM[0][j-1];
        }
        
        for (int i = 1;i<r;i++){
            for (int j = 1; j<c; j++){
                IM[i][j] = IM[i-1][j] + IM[i][j-1] - IM[i-1][j-1] + IM[i][j];
            }
        }
    }
    
    int getSum(int row, int col){
        if (row<0||col<0) return 0;
        
        return IM[row][col];
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // int Ar = row1-1;
        // int Ac = col1-1;
        // int Br = row2;
        // int Bc = col1-1;
        // int Cr = row1-1;
        // int Cc = col2;
        // int Dr = col2;
        // int Dc = row2;
        
        return IM[row2][col2] + getSum(row1-1,col1-1) - getSum(row2, col1-1) - getSum(row1-1, col2);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */