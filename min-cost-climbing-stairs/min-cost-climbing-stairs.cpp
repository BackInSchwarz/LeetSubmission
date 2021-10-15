class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        
        int n = cost.size();
        vector<int> dp(n+1, 0);
        
        // dp[0] = 0;
        dp[0] = cost[0];
        // cout<<dp[0]<<endl;
        if (n==1) return dp[n-1];
        
        
        dp[1] = min(dp[0]+ cost[1], cost[1]);
        // cout<<dp[1]<<endl;
        if (n==2) return min(dp[0], dp[1]);
        
        for (int i =2; i<n;i++){
            dp[i] = min(dp[i-1] + cost[i], dp[i-2] + cost[i]);
            // cout<<dp[i]<<endl;
        }
        dp[n] = min(dp[n-1], dp[n-2]);
        
        return dp[n];
    }
};