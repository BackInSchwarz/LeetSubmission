class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> ht;
        for (int i =0; i<nums.size(); i++){
            if (ht.find(target-nums[i]) != ht.end())
                return vector<int>{i, ht[target-nums[i]]};
            ht[nums[i]] = i;
        }
        
        return {};
    }
};