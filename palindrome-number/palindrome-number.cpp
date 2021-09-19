class Solution {
public:
    bool isPalindrome(int x) {
        string str = to_string(x);
        int N = str.size();
        if (N==0) return true;
        
        int i = 0;
        int j = N-1;
        while(i<=j){
            if (str[i] == str[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
};