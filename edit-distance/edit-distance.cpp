class Solution {
public:
    int minDistance(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        
        if (l1*l2==0) return l1+l2;
        
        vector<vector<int>> dp(l1+1, vector<int>(l2+1,0));
        
        for (int i = 0;i<=l1;i++){
            dp[i][0]  = i;
        }

        for (int j = 0;j<=l2;j++){
            dp[0][j]  = j;
        }
        
        for (int i = 1;i<=l1;i++){
            for (int j = 1;j<=l2;j++){
                if (word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                } 
                else{
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1;
                }
            }
        }
        
        return dp[l1][l2];
    }
};