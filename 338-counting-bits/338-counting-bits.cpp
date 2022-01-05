class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1,0);
        int prev2power = 2;

        dp[0] = 0;
        
        if (n == 0) return dp;
        dp[1] = 1;
        if (n == 1) return dp;
        dp[2] = 1;
        
        for (int i = 3; i<=n; i++){
            if ((i&(i-1))==0){
                prev2power = i;
                dp[i] = 1;
            }else{
                dp[i] = 1 + dp[ i - prev2power];
            }
                
        }
        
        return dp;
    }
};