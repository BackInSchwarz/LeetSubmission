class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> ans;
        for (char c:s){
            
            if (c>='0' and c<='9'){
                ans.push_back(c);
                continue;
            }
            
            if (c>='a' and c<='z'){
                ans.push_back(c);
                continue;
            }
            
            if (c>='A' and c<='Z'){
                ans.push_back('a'+ (c-'A'));
                continue;
            }
        }
        
        if (ans.size()==0) return true;
        
        for (int i = 0; i < ans.size(); i++){
            if (ans[i] != ans[ans.size()-1-i])
                return false;
        }
        
        return true;
    }
};