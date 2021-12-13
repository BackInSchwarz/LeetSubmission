class Solution {
public:
    int maxPower(string s) {
        int n = s.size();
        if(n==1) return n;
        char pre = s[0];
        int cnt=1;
        int maxCnt=1;
        for(int i=1;i<n;i++){
            if(s[i]==pre){
                cnt++;
            }else{
                cnt=1;
                pre= s[i];
            }
            maxCnt = max(cnt, maxCnt);
        }
        
        return maxCnt;
    }
};