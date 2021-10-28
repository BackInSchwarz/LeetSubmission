class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int prev = 0;
        int minposInt = 0;
        int maxposInt = 0;
        for (int i = 0;i<nums.size();i++){
            if (nums[i]<=0) {
                
                continue;
            }
            
            if (prev<=0 && nums[i]>0){
                minposInt = nums[i];
            }
            if (minposInt>1) return 1;
            
            if (i ==nums.size()-1){
                maxposInt = nums[i];
            }
            
            if ((i<(nums.size()-1))&&((nums[i+1] - nums[i])>1)) 
                return nums[i]+1;
            
            
            
            prev = nums[i];
            
        }
        
        return maxposInt+1;
    }
};