class Solution {
public:
    map<int, int> dp;
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        int ans;
        if (dp.find(n)!=dp.end()) return dp[n];
        ans = climbStairs(n-1) + climbStairs(n-2);
        dp[n] = ans;
        return ans;
    }
};