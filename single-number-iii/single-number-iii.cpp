class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int ab = nums[0];
        for (int i = 1; i<nums.size();i++){
            ab = ab^nums[i];
        }
        int diffbitN = 0;
        for (int i = 0;i <32;i++){
            if (((ab>>i)&1)==1){
                diffbitN=i;
                break;
            }
        }
        int a;
        int a_set = 0;
        int b;
        int b_set = 0;
        for (int i = 0; i<nums.size();i++){
            if (((nums[i]>>diffbitN)&1)==1){
                if (a_set==0){
                    a = nums[i];
                    a_set=1;
                }else{
                    a = a^nums[i];
                }
            }else{
                if (b_set==0){
                    b = nums[i];
                    b_set=1;
                }else{
                    b = b^nums[i];
                }
                
            }
        }
        return {a, b};
    }
};