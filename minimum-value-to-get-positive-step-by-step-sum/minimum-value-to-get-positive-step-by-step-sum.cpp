class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int ans = INT_MAX;
        int sum = 0;
        for (int num:nums){
            sum+=num;
            ans = min(sum, ans);
        }
        
        return max(1,1-ans);
    }
};