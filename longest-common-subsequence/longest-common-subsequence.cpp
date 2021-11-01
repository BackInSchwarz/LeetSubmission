class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n_t1 = text1.length();
        int n_t2 = text2.length();
        
        vector<vector<int>> dp(n_t1+1, vector<int>(n_t2+1,0));
        
        for (int i = 1;i<=n_t1;i++){
            for (int j = 1;j<=n_t2;j++){
                if (text1[i-1]==text2[j-1]){
                    dp[i][j]= dp[i-1][j-1] + 1;
                }else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        
        return dp[n_t1][n_t2];
                               
                        
    }
};