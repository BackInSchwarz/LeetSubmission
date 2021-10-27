class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        if (abs(n-m)>1) return false;
        if ((n==0)&&(m==0)) return false;
        if ((n==1)&&(m==0)) return true;
        if ((n==0)&&(m==1)) return true;
        
        //equal length case
        if (n==m){
            int diffcnt = 0;
            for (int i = 0;i<n;i++){
                if (s[i]!=t[i]) diffcnt+=1;
            }
            
            if (diffcnt==1){
                return true;
            }else{
                return false;
            }
        }
        
        //one long one short case
        // s is longer. n=m+1;
        if (n<m) {
            swap(s,t);
            swap(n,m);
        }
        
        int diffallow = 1;
        // int longshift = 0;
        
        for (int i = 0;i<m;i++){
            if (diffallow==1){
                if ((s[i]!=t[i])){
                    if (s[i+1]==t[i]){
                        diffallow--;
                    }else{
                        // cout<<s[i]<<s[i+1]<<endl;
                        // cout<<t[i]<<endl;
                        // cout<<"case 1"<<endl;
                        return false;
                    }
                }
            }else{
                if (s[i+1]!=t[i]) {
                    cout<<"case 2"<<endl;
                    return false;
                }
            }
            
        }
        // cout<<diffallow;
        return true;
        
        
    }
};