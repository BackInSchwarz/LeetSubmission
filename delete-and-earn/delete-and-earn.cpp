class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> count(10001,0);
        for (int x:nums) count[x]++;
        int avoid = 0, useit = 0, prev= -1;
        
        for (int k = 0; k<=10000; ++k) {
            if (count[k] == 0) continue;
            
            int m = max(avoid, useit);
            if ((k-1)!=prev){
                useit = k * count[k] + m;
                avoid = m;
            }else{
                useit = k * count[k] + avoid;
                avoid = m;
            }
            
            prev = k;
        }
        return max(avoid, useit);
    }
};