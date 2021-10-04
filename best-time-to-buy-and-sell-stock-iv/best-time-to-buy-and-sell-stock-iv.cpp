class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k==0) return 0;
        int dp[2][2*k];
        for (int i = 0; i<2*k; i++){
            dp[0][i] = (i%2 == 0) ?INT_MIN:0;
            dp[1][i] = (i%2 == 0) ?INT_MIN:0;
        }
        int cur = 0;
        int next = 1;
        for (int i = 0; i<prices.size(); i++){
            for (int j = 0;j<2*k;j++){
                if (j==0){
                    dp[next][j] = max(dp[cur][j], -prices[i]);
                }else{
                    if ((j%2)==0)
                        dp[next][j] = max(dp[cur][j], dp[cur][j-1]-prices[i]);
                    if ((j%2)==1)
                        dp[next][j] = max(dp[cur][j], dp[cur][j-1]+prices[i]);
                }
            }
            swap(cur, next);
        }
        
        int answer = 0;
        
        for (int i = 0; i<k;i++)
            answer = max(answer, dp[cur][i*2+1]);
        
        return answer;
    }
};