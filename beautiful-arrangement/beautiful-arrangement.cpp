class Solution {
public:
    int ans;
    
    void backtrack(int& n, vector<bool>& used, int numUsed){
        if (numUsed==n){
            ans+=1;
            return;
        }
        int curIndex = numUsed+1;
        for (int i=1;i<=n;i++){//iterate every possible number i. 
            if (used[i]==true) continue;
            
            if (i%curIndex==0 || curIndex%i==0){
                used[i]= true;
                backtrack(n, used, numUsed+1);
                used[i]= false;
            }
            
        }
        
        return;
        
    }
    
    int countArrangement(int n) {
        vector<bool> used(n+1,false);
        ans = 0;
        backtrack(n, used, 0);
        
        return ans;
    }
};