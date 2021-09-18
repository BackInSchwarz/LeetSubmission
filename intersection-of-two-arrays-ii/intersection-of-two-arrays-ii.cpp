class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> ht;
        for (int i=0; i<nums1.size();i++){
            ht[nums1[i]]++;
        }
        vector<int> ans;
        for (int i = 0; i<nums2.size();i++){
            if (ht.find(nums2[i])==ht.end())
                continue;
            else{
                if (ht[nums2[i]]>0){
                    ans.push_back(nums2[i]);
                    ht[nums2[i]]--;
                }
            }
        }
        return ans;
    }
};