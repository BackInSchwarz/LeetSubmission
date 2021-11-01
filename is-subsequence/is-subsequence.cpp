class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sn = s.length();
        int tn = t.length();
        
        int sInd = 0;
        for (char c:t){
            if (c==s[sInd]){
                sInd+=1;
            }
        }
        
        if (sInd == sn)
            return true;
        
        return false;
    }
};