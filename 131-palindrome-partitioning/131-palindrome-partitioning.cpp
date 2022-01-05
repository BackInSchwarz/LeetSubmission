class Solution {
public:
    vector<vector<string>> ans;
    
    bool isPalindrome(string & s, int start, int end){
        while(start<=end){
            if (s[start]!=s[end]) return false;
            start++;
            end--;
        }
        
        return true;
    }
    
    void helper(string & s, int start, vector<string>& curAns){
        if (start>=s.length()){
            ans.push_back(curAns);
            return;
        }
        
        for (int i = start; i<s.length(); i++){
            if (isPalindrome(s, start, i)){// inclusive
                curAns.push_back(s.substr(start, i-start + 1));
                helper(s, i+1, curAns);
                curAns.pop_back();
            }
        }
        
        return;
    }
    
    vector<vector<string>> partition(string s) {
        
        ans.clear();
        
        vector<string> curAns(0);
        
        helper(s, 0, curAns);
        
        return ans;
    }
};