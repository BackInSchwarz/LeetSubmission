class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return 0;
        vector<int> dp(n,INT_MAX);
        dp[0] = 0;
        int furthest = nums[0];
        for (int i = 0; i<n; i++){
            if (i>furthest) return 0;
            
            furthest = max(furthest, nums[i] + i);
            
            for (int j = 0; j<i; j++){
                if (i<=(nums[j] + j) && dp[j]!=INT_MAX)
                    dp[i] = min(dp[i], dp[j]+1); 
            }
        }
        return dp[n-1];
    }
};