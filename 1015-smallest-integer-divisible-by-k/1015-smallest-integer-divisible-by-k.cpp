class Solution {
public:
    int smallestRepunitDivByK(int k) {
        set<int> rem;
        int cur = 1;
        int len = 1;
        int remain = 1%k;
        while( remain!=0 && (rem.find(remain)==rem.end())){
            rem.insert(remain);
            cur = remain*10 + 1;
            len ++;
            remain = cur%k;
            
        }
        
        if (remain == 0)
            return len;
        
        return -1;
    }
};