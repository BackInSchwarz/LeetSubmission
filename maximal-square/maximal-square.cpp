class Solution {
public:
    int getSum(vector<vector<int>>& matrix, int i,int j){
        if (i<0||j<0) return 0;
        
        return matrix[i][j];
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        //find pre fix sum
        

        
        int r = matrix.size();
        int c = matrix[0].size();
        
        vector<vector<int>> dp(r, vector<int>(c,0));
        
        dp[0][0] = matrix[0][0]-'0';
        
        for (int i = 1;i<r;i++){
            int temp = dp[i-1][0] + (matrix[i][0]-'0');
            // cout<<temp<<endl;
            dp[i][0]=temp;
        }
        
        for (int i = 1;i<c;i++){
            int temp = dp[0][i-1] + (matrix[0][i] - '0');
            dp[0][i]=temp;
        }
        
        for (int i=1;i<r;i++){
            for (int j = 1;j<c;j++){
                int temp = (matrix[i][j]-'0');
                dp[i][j]  = temp +  dp[i-1][j]+dp[i][j-1] - dp[i-1][j-1];
            }
        }
        // for (int i =0;i<r;i++){
        //     for (int j = 0;j<c;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        //try every possible square. 
            // n>1 case
        int n = min(r,c);
        
        for (int k = n;k>1;k--){
            for(int i = k-1;i<r;i++){
                for (int j=k-1;j<c;j++){
                    int totalsum = getSum(dp, i,j) +getSum(dp, i-k,j-k) - getSum(dp, i-k,j) - getSum(dp, i,j-k);
                    
                    // cout<<k<<" "<<i<<" "<<j<<" "<<totalsum<<endl;
                    if (totalsum ==(k*k)) return k*k; 
                }
            }
        }
        
            // n=1 case check last in the matrix
        if (dp[r-1][c-1]>0) return 1;
        
        
        return 0;
    }
};