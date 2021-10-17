class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n==1) return true;
        int curMax = nums[0];
        
        for (int i = 0; i<n;i++){
            if (i>curMax) return false;
            curMax = max(curMax, i + nums[i]);
            if (curMax>=(n-1)) return true;
            
        }
        return false;
    }
};