class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        //check every bit of the left and right. 
        int res = 0;
        long lleft = left;
        long lright = right;
        for (int i = 0; i<32;i++){
            // if that bit of left and right are both 1
            if (((lleft>>i)&1 ==1) && ((lright>>i)&1 ==1)){
                //add 1 to that bit in left and check if it is less than right
                // temp = left + (1<<i);
                if ((lleft + (1<<i))>=lright){
                    // if no, it is 1
                    res += 1<<i;
                }
                    

            }

            // else
                //the answer is 0
        }
        
        return res;

    }
};