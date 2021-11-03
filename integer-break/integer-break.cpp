class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, 0);
        
        dp[0] = 0;
        dp[1] = 0;
        // if (n==2) return 1;
        dp[2] = 1;
        for (int i = 3;i<=n;i++){
            int curMax = INT_MIN;
            for(int j = 1;j<i;j++){
                dp[i] = max(max(dp[i], j*dp[i-j]), j*(i-j));
            }
            // dp[i] = max
        }
        
        return dp[n];
    }
};