class Solution {
public:
    int kthFactor(int n, int k) {
        
        int cnt = 0;
        int curDivider = 1;
        
        while (curDivider<=n){
            if ( n%curDivider == 0){
                cnt++;
            }
            
            if (cnt == k) return curDivider;
            
            curDivider++;
        }
        
        return -1;
        
    }
};