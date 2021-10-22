class Solution {
public:
    string frequencySort(string s) {
        //count everything once
        int n = s.length();
        map<char,int> hm;
        for (char c:s){
            if (hm.find(c)!=hm.end()){
                hm[c]+=1;
            }else{
                hm[c] = 1;
            }
        }
        //bucket sort first
        vector<vector<char>> bucket(n+1, vector<char>(0));
        
        for (const auto &[key,value]:hm){
            bucket[value].push_back(key);
        }
        
        string ans;
        //write it back to the string once.
        for (int i = n;i>0;i--){
            if (bucket[i].size()==0)
                continue;
            for (const char &c:bucket[i]){
                for (int j=i;j>0;j--)
                    ans.push_back(c);
            }
        }
        
        return ans;
    }
};