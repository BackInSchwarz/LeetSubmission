// include <Math.h>
class Solution {
public:

    int maxProduct(vector<int>& nums) {
        if (nums.size()==0) return 0;
        
        int maxN = nums[0];
        int minN = nums[0];
        int resN = nums[0];
        
        for (int i = 1; i <nums.size();i++){
            int tem = maxN;
            maxN = max(max(maxN*nums[i], minN*nums[i]), nums[i]);
            minN = min(min(tem*nums[i], minN*nums[i]), nums[i]);
            
            resN = max(maxN, resN);
        }
        
        return resN;
    }
};