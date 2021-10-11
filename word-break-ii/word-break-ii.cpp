class Solution {
public:
    
    void helper(unordered_set<string> &dict, string &s, vector<string> &ans, string curAns, int start){
        //memorization??
        //end case
        // cout<<start<<endl;
        if (start > (s.length()-1))
            ans.push_back(curAns);
        
        //general case
        for (int i = start; i<(s.length()); i++){
            // cout<<s.substr(start, i-start+1)<<endl;
            if (dict.find(s.substr(start, i-start+1))!=dict.end()){
                // initial case
                if (start == 0){
                    helper(dict, s, ans, curAns+s.substr(start, i-start+1), i+1);
                }else{
                    // genearl case
                    helper(dict, s, ans, curAns+" "+s.substr(start, i-start+1), i+1);
                }
            }
        }
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<string> ans;
        string curAns;
        helper(dict, s, ans, curAns, 0);
        
        return ans;
        
    }
};