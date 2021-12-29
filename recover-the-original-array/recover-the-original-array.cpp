class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {  
        sort(nums.begin(), nums.end());
        int n2 = nums.size();
        int n = n2/2;
        int a = nums[0];
        vector<int> ans(n,0);
      
        for (int i = 1; i <= n; i++)
        {
            int k2 = nums[i] - a;
            if (k2 % 2 == 1 || k2 == 0 || nums[i] == nums[i - 1]) continue;   
            int k = k2/2;
            int i1 = 1;
            int i2 = 0;
            ans[0] = a + k;
            for (int j = 1; j < n2; j++)
            {
                int nj = nums[j];
                if (i2 < i1 && (nj == ans[i2] + k)) {
                    //append nj to higher
                    i2++;
                } else if (i1 < n) {
                    // append nj to lower 
                    // update ans
                    ans[i1++] = nj + k;
                } else {
                    break;
                }
            }
        
            if (i1 == n && i2 == n)
                break;

        }
      
        return ans; 
    }
};

// [7,5,3,9,1,11,7,5,11,3,9,9]
// [11,6,3,4,8,7,8,7,9,8,9,10,10,2,1,9]