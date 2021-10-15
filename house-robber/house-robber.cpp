class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return nums[0];
        if (n==2) return max(nums[0], nums[1]);
        
        vector<int> dp(n,0);
        vector<int> mx(n,0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        mx[0] = dp[0];
        for (int i = 2; i<n;i++){
            dp[i] = nums[i] + mx[i-2];
            mx[i-1] = max(mx[i-2], dp[i-1]);
        }
        
        return max(dp[n-1], dp[n-2]);
    }
};

// Init case
    // n == 1, return nums[n-1];
    // n == 2, return max(nums[0], nums[1])
// general case
    // n == j, j>2
        // dp[j] = max_till_j_m_2 + 