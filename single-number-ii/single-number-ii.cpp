class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> bits(32,0);
        for (int x:nums){
            for (int i = 0;i<32; i++){
                bits[i] += (x>>i)&1;
            }
        }
        int ans = 0;
        for (int i = 0;i<32; i++){
            ans+= (bits[i]%3)<<i;
        }
        return ans;
    }
};