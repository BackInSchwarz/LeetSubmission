class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> l(n, 1);
        vector<int> r(n, 1);
        l[0]=nums[0];
        for (int i =1;i<n-1;i++){
            l[i]=l[i-1]*nums[i];
            // cout<<l[i]<<endl;
        }
        
        r[n-1]=nums[n-1];
        for (int i=n-2;i>=1;i--){
            r[i]=r[i+1]*nums[i];
            // cout<<r[i]<<endl;
        }
        
        vector<int> ans(n,0);
        
        for (int i =0;i<ans.size();i++){

            int lpart=0;
            int rpart=0;
            if ((i-1)<0){
                lpart=1;
            } else{
                lpart=l[i-1];
            }
            
            if ((i+1)>(n-1)){
                rpart=1;
            } else{
                rpart=r[i+1];
            }
            
            // cout<<lpart<<" "<<rpart<<endl;
            
            ans[i]=lpart*rpart;

        }
        
        return ans;
    }
};