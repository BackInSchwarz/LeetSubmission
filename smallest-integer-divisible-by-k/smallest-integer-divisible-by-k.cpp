class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if (k%2==0) return -1;
        
        
        int rem = 1;
        int length_N = 1;
        
        
        unordered_set<int> hs;
        
        while (rem%k!=0){
            int N = rem * 10 +1;
            rem = N % k;
            length_N++;
            
            if (hs.find(rem)!=hs.end()){
                return -1;
            }else{
                hs.insert(rem);
            }
        }
        
        return length_N;
    }
};