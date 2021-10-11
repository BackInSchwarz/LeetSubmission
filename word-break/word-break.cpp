class Solution {
public:
    map<int, bool> dp;
    bool helper(unordered_set<string> &dict, string &s, int start){
        if (start>(s.length()-1)) return true;
        // general case. 
        
        if (dp.find(start)!=dp.end()) return dp[start];
        
        bool ans = false;
        // for (int i = start; i< s.length(); i++){
        for (int i = (s.length()-1); i>=start; i--){
            if (dict.find(s.substr(start, i-start+1))!= dict.end()){
                ans = ans || helper(dict, s, start + (i-start+1));
                
                // if ((i == (s.length()-1)) && (ans == true))
                //     break;
                if (ans==true)
                    break;
            }    
        }
        
        dp[start] = ans;
        
        return ans;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return helper(dict, s, 0);
    }
};


//recursion without actual answer. just a bool 
//variables. 
    //Source, 
    //start: till which index, it is processed
//logic
    //end condition
    //initial condition
    //general condition.
//memorization
    //