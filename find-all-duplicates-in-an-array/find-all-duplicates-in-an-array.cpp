class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        map<int, int> hp;
        for (int num: nums){
            if (hp.find(num)==hp.end()){
                hp[num]=1;
            }else{
                hp[num]+=1;
            }
        }
        
        
        vector<int> ans;
        
        for (auto const&[key, val]: hp){
            if (val==2)
                ans.push_back(key);
        }
        
        return ans;
    }
};