class Solution {
public:
    vector<int> dp;
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
    
    int helper(string &s, int start, int& strN){

        if ((strN-start)<=1) return 0;
        if (dp[start]!=-1) return dp[start];
        int ans = INT_MAX;
        for (int i = (strN-1);i>=start;i--){
            if (isPalindrome(s, start, i)){
                if (i ==(strN-1)){
                    ans = min(ans, 0); 
                }else{
                    ans = min(ans, 1+ helper(s, i+1, strN));
                }
            }      
        }
        dp[start]  = ans;
        return ans;
    }
    int minCut(string s) {
        int strN = s.length();
        dp.resize(strN,-1);
        return helper(s, 0, strN);
    }
};