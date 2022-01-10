class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int carry = 0;
        
        for ( int i = 0; i<max(a.length(), b.length()); i++){
            
            int ai = 0;
            int bi = 0;
            
            if ( i < a.length() ){
                
                ai = a[i] - '0';
                
            }else{
                
                ai = 0;
            }
            
            if ( i < b.length() )
            {
                bi = b[i] - '0';
            }else{
                bi = 0;
            }
            
            int cur = ai + bi + carry;
            carry = (cur / 2);
            cur = cur%2;
            
            ans.push_back( cur + '0');
            
        }
        
        if (carry == 1)
            ans.push_back('1');
        
        reverse( ans.begin(), ans.end());
        
        return ans;
    }
};