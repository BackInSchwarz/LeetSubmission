class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int r = nums1.size();
        int c = nums2.size();
        
        vector<vector<int>> dp(r, vector<int>(c,0));
        int ans = INT_MIN;
        for(int i =0;i<r;i++){
            dp[i][0] = (nums1[i]==nums2[0])?1:0;
            ans = max(ans,dp[i][0]);
        }

        for(int j =0;j<c;j++){
            dp[0][j] = (nums1[0]==nums2[j])?1:0;
            ans = max(ans,dp[0][j] );
        }
        
        for (int i = 1;i<r;i++){
            for (int j = 1;j<c;j++){
                
                if (nums1[i] == nums2[j])
                    dp[i][j] = 1 + dp[i-1][j-1]; 
                
                ans = max(ans,dp[i][j]);
            }
        }
        
        // for (int i = 0;i<r;i++){
        //     for (int j = 0;j<c;j++){
        //        cout<<dp[i][j]; 
        //     }
        //     cout<<endl;
        // }
        
        
        return ans;
    }
};