class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        vector<int> ws(nums.size(),0);
        vector<int> dp(nums.size(),0);
        dp[0] = 1;
        int ans = 1;
        for (int i = 1;i<nums.size();i++){
            int curMax = 1;
            int curWS = 0;
            for(int j = 0;j<i;j++){
                if (ws[j]==0){
                    if (nums[i]>nums[j]){
                        if (curMax<(dp[j]+1)){
                            curMax = dp[j]+1;
                            curWS = 1;
                        }
                    }else if(nums[i]<nums[i-1]){
                        if (curMax<(dp[j]+1)){
                            curMax = dp[j]+1;
                            curWS = -1;
                        }
                    }else{
                        if (curMax<1){
                            curMax = 1;
                            curWS = 0;
                        }
                    }
                    continue;
                }

                if (ws[j]==1){
                    if (nums[i]<nums[j]){
                        if (curMax<(dp[j]+1)){
                            curMax = dp[j]+1;
                            curWS = -1;
                        }
                    }
                    continue;
                }

                if (ws[j]==-1){
                    if (nums[i]>nums[j]){
                        if (curMax<(dp[j]+1)){
                            curMax = dp[j]+1;
                            curWS = 1;
                        }
                    continue;
                    }
                }   

            }
            
            dp[i] = curMax;
            ws[i] = curWS;
            ans = max(ans, dp[i]);
        }
        
        return ans;
    }
};