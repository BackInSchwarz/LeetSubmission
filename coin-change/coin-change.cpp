class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // set<int> coinsSet(coins.begin(), coins.end());
        int n = coins.size();
        vector<int> dp(amount+1, INT_MAX);
        
        dp[0]=0;
        
        for (int i = 1;i<=amount;i++){
            int curBest = INT_MAX;
            for (const int& coin:coins){
                if ((i-coin)>=0){
                    if (dp[i-coin]!=INT_MAX){
                        curBest = min(curBest, dp[i-coin]+1);
                    }
                }
            }
            
            dp[i] =curBest;
        }
        
        if (dp[amount]!=INT_MAX) return dp[amount];
        
        return -1;
    }
};