class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size()==1) return 1;
        // vector<int> curMax(nums.size(), INT_MAX);
        // // int ans = 0;
        // curMax[0] = nums[0];
        // for (int i =1;i<nums.size();i++){
        //     if (nums[i]>curMax[i-1]){
        //         curMax[i] = nums[i];
        //     }else{
        //         curMax[i] = curMax[i-1];
        //     }
        // }
        int ans=INT_MIN;
        vector<int> dp(nums.size(),0);
        dp[0] = 1;
        for (int i=1;i<nums.size();i++){
            int curLong = INT_MIN;
            for (int j = 0;j<i;j++){
                if (nums[i]>nums[j]){
                    curLong = max(curLong, dp[j]+1);
                }else{
                    curLong = max(curLong, 1);
                }
            }
            dp[i] = curLong;
            if (dp[i]>ans) ans = dp[i];
            // cout<<i<<' '<<dp[i]<<endl;11
        }
        
        return ans;
    }
};