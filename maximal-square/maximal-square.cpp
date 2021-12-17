class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        int curMax = 0;
        
        for (int i = 0; i<r; i++){
            if (matrix[i][0]=='1'){
                curMax = 1;
                break;
            }
        }
        
        for (int j = 0; j<c; j++){
            if (matrix[0][j]=='1'){
                curMax = 1;
                break;
            }
        }
        
        
        for (int i = 1; i<r ;i++){
            for (int j = 1; j < c; j++){
                if (matrix[i][j]=='0') continue;
                
                int topL = matrix[i-1][j-1] - '0';
                int l = matrix[i-0][j-1] - '0';
                int r = matrix[i-1][j-0] - '0';
                
                int ans = min( l, min( topL, r) ) + 1;
                
                if ((ans*ans) > curMax) curMax = (ans*ans);
                
                matrix[i][j] = (ans + '0');
            }
        }
        
        
        return curMax;
    }
};