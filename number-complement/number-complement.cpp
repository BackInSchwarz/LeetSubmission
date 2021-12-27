class Solution {
public:
    int findComplement(int num) {
        int digits = 1;
        int cur = num;
        while(cur!=1){
            digits++;
            cur = cur/2;
        }
        
        // cout<< " digits are "<< digits<<endl;
        
        int ans = 0;
        
        for (int i = 0; i<digits; i++){
            // cout << "num>>i is : "<< (num>>i) << endl;
            // cout << "(num>>i)&1 is : "<< ((num>>i)&1) << endl;
            if ( ((num>>i)&1) == 0){
                ans = ans + (1<<i);
                // cout<<" ans is : "<< ans <<endl;
            }
                
        }
        
        return ans;
    }
};