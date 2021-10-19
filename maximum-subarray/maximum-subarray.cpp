class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curMax;
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];
        curMax = nums[0];
        if (n==1) return curMax;
        
        for (int i =1; i<n;i++){
            dp[i] = max(dp[i-1]+nums[i],nums[i]);
            if (dp[i]>curMax) curMax = dp[i];
        }
        
        
        return curMax;
        
        
        
    }
};