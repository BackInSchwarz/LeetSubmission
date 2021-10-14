class Solution {
public:
//     // int ans;
    
//     int numSquares(int n) {
//         // if (n==1) return 1;
//         // if (n==2) return 2;
//         vector<int> dp(n+1,n);
//         dp[0] = 0;
//         dp[1] = 1;
//         dp[2] = 2;
//         // if (dp.find(n)!=dp.end()) return dp[n];
//         // if ((sqrt(n)*sqrt(n))==n) {
//         //     dp[n] = 1;
//         //     return dp[n];
//         // }
//         // int ans = n;
//         // int i = 1;
//         // while((n-i)>=i){
//         //     ans = min(ans, numSquares(n-i)+numSquares(i));
//         //     i++;
//         // }
//         // dp[n] = ans;
//         for (int i =3; i <=n; i++){
//             if ((sqrt(i)*sqrt(i))==i){
//                 dp[i] = 1;
//                 continue;
//             }
//             for (int j = 1; j<i;j++){
//                 if ((n-j)<j) break;
//                 dp[i] = min(dp[i], dp[j]+ dp[n-j]);
//             }
//         }
//         return dp[n];
//     }
    int numSquares(int n) {
    static vector<int> dp {0};
    int m = dp.size();
    dp.resize(max(m, n+1), INT_MAX);
    for (int i=1, i2; (i2 = i*i)<=n; ++i)
        for (int j=max(m, i2); j<=n; ++j)
            if (dp[j] > dp[j-i2] + 1)
                dp[j] = dp[j-i2] + 1;
    return dp[n];
}
};



// DP. 
    // n = 1, v = 1;
    // n = 2, v = 2;
    // n = 3, v = 3;
    // n = k, 
        // iterate through [k - 1, (k-1)/2] if k is even, [k-1, (k-1)/2) if k is odd. 





int numSquares(int n) {
    static vector<int> dp {0};
    int m = dp.size();
    dp.resize(max(m, n+1), INT_MAX);
    for (int i=1, i2; (i2 = i*i)<=n; ++i)
        for (int j=max(m, i2); j<=n; ++j)
            if (dp[j] > dp[j-i2] + 1)
                dp[j] = dp[j-i2] + 1;
    return dp[n];
}