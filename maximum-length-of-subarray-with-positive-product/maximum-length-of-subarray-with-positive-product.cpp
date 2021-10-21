class Solution {
public:
    int helper(vector<int>& nums, int start, int end){
        if (start>end) return 0;
        int neg = 0;
        for (int i = start; i <=end; i++){
            if (nums[i]<0) neg+=1;
            if (nums[i] ==0)
                return max(helper(nums, start , i-1), helper(nums, i+1,end));
        }
        
        if (neg%2==0)
            return (end-start+1);
        
        int tillfirstnegleft = 1;
        int tillfirstnegright = 1;
        for(int i = start; i<=end; i++){
            if (nums[i]>0) 
                tillfirstnegleft+=1;
            else
                break;
        }
        
        for(int i = end; i>=start; i--){
            if (nums[i]>0) 
                tillfirstnegright+=1;
            else
                break;
        }
        
        return (end-start+1) - min(tillfirstnegleft, tillfirstnegright);
    }
    
    int getMaxLen(vector<int>& nums) {
        return helper(nums, 0,nums.size()-1);
    }
};