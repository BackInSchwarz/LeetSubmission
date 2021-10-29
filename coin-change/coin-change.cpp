class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,0);
        
        dp[0]=0;
        for (int i = 1;i<=amount;i++){
            int curMin = INT_MAX;
            
            for (auto const&coin:coins){
                if ((i-coin)>=0){
                    if (dp[i-coin]!=INT_MAX)
                        curMin = min(curMin, 1+dp[i-coin]);
                }
            }
            
            dp[i] = curMin;
        }
        
        if (dp[amount]==INT_MAX) return -1;
        
        return dp[amount];
    }
};