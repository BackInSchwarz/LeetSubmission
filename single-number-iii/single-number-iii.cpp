class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xy = 0;
        for (int i = 0;i<nums.size();i++){
            xy = xy^nums[i];
        }
        
        long diff = xy&(-xy);
        
        int x = 0;
        for (int i = 0;i<nums.size();i++){
            if ((nums[i]&diff)!=0) x^=nums[i];
        }
        
        return {x, int(xy^x)};
    }
};