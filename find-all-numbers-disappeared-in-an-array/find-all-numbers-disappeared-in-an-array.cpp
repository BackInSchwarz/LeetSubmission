class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        //sort
        sort(nums.begin(), nums.end());
        //iterate through the array and detect jump and push the answer into the array.
        int n = nums.size();
        int curNum=1;
        vector<int> ans;
        for(auto num:nums){

            while(curNum<num&&curNum<=n){
                ans.push_back(curNum);
                curNum++;
            }
            if (curNum==num){
                curNum++;
                continue;
            }
            if (curNum==n+1) break;
            
        }
        while(curNum<=n){
            ans.push_back(curNum);
            curNum++;
        }
        
        return ans;
    }
};