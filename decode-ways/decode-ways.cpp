class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n,0);
        if (s[0]!='0') dp[0] = 1;
        if (n>1){
            if (s[1]!='0') dp[1] += dp[0];
            int temp = (s[0]-'0')*10 + (s[1]-'0');
            if ((temp>=10) && (temp<=26)) dp[1]+=1;
        }

        for (int i = 2;i<n;i++){
            if (s[i]!='0')
                dp[i]+= dp[i-1];
            int temp = (s[i-1]-'0')*10 + (s[i]-'0');
            if ((temp>=10) && (temp<=26)) dp[i]+=dp[i-2];
        }
        return dp[n-1];
    }
};