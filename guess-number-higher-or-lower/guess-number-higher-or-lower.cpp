/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long ln = n;
        long l = 1;
        long r = ln + 1;
        while (l<r){
            long m = (l + r) / 2;
            
            if (guess(m) == 0)
                return m;
            
            if (guess(m)==-1){
                r = m;
            }else{
                l = m + 1;
            }
        }
        return 0;
    }
};


// binary search with guess API
// binary search
    // initialization
        //l = 1
        //r = n+1
    // loop end condition
        //l>r
    // find answer condition
        // guess(m) = 0
    // left
        //r = m+1
    // right
        //l = m