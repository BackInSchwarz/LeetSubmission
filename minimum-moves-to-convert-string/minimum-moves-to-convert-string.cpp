class Solution {
public:
    int minimumMoves(string s) {
        int ans=0;
        int N = s.length();
        for (int i = 0; i<s.length();i++){
            if (s[i]=='O')
                continue;
            if (s[i]=='X'){
                ans+=1;
                i = min((i+2), N-1);
            }
        }
        return ans;
    }
};