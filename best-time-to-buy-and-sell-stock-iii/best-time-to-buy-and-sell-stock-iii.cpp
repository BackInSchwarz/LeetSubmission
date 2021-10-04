class Solution {
public:
    // int maxProfithelper(vector<int>& prices, int start, int end){
    //     if ((end-start) ==0) return 0;
    //     int maxProfit = 0;
    //     int curlow = prices[start];
    //     for (int i = start; i <=end; i++){
    //         // int curProfit = prices[i] - curlow;
    //         curlow = min(curlow, prices[i]);
    //         // if ((prices[i] - curlow)>maxProfit)
    //         maxProfit = max(prices[i] - curlow, maxProfit);
    //     }
    //     return maxProfit;
    // }
    int maxProfit(vector<int>& prices) {
        int N = prices.size();
        int maxProfit = 0;
        // if (N<=2)
        //     return max(maxProfit, prices[1] - prices[0]);
        // One transaction
        // int maxOne = maxProfithelper(prices, 0, N-1);
        // maxProfit = max(maxProfit, maxOne);
        // if (maxProfit==0) return 0;
        // Two transaction
//         int leftcurmin;
//         int rightcurmax;
//         for (int i=)
//         for (int i=1; i<N-1; i++){
//             int sum = maxProfithelper(prices, 0, i)+maxProfithelper(prices, i, N-1);
//             maxProfit = max(maxProfit, sum);
//             // cout<< maxProfithelper(prices, 0, i) << " "<<maxProfithelper(prices, i, N-1)<<endl;

//         }
        vector<int> l_dp(N,0);
        vector<int> r_dp(N,0);
        int curlo = prices[0];
        int curhi = prices[N-1];
        int l_maxProfit = 0;
        int r_maxProfit = 0;
        for (int i = 0; i<N;i++){
            curlo = min(curlo, prices[i]);
            curhi = max(curhi, prices[N-1-i]);
            l_maxProfit = max(prices[i] - curlo, l_maxProfit);
            r_maxProfit = max(curhi - prices[N-1-i], r_maxProfit);
            l_dp[i] = l_maxProfit;
            r_dp[N-1-i] = r_maxProfit;
        }
        
        for (int i = 0; i<N;i++){
            maxProfit = max(maxProfit, l_dp[i] + r_dp[i] );
        }
        
        return maxProfit;
    }
};