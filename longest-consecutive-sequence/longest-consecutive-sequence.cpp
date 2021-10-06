class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size()==0 ) return 0;
        if (nums.size()==1 ) return 1;
        sort(nums.begin(), nums.end());
        int lastNum = 0;
        int maxSeq = 1;
        int curSeq = 1;
        for (int i = 0; i<nums.size();i++){
            if (i == 0){
                lastNum = nums[0];
                continue;
            }
            if ((nums[i] - lastNum)==1){
                curSeq+=1;
                maxSeq = max(maxSeq, curSeq);
            }else{
                curSeq = 1;
            }
            
            lastNum = nums[i];
            while((i+1)<nums.size() and nums[i]==nums[i+1])
                i++;
        }
        
        return maxSeq;
    }
};