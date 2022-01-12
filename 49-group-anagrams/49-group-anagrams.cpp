class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hm;
        
        for (string str:strs){
            
            string temp = str;
            
            sort(str.begin(), str.end());
            
            hm[str].push_back(temp);

        }
        
        vector<vector<string>> ans;
        
        for (auto [key, val]: hm){
            ans.push_back(val);
        }
        
        return ans;
    }
};