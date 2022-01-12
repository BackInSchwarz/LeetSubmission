class Solution {
public:
    string intToRoman(int num) {
        vector<string> letters = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV","I"};
        vector<int> vals = {1000, 900, 500, 400, 100, 90, 50, 40,  10, 9,  5, 4, 1};
        
        int curInd = 0;
        
        string ans="";
        
        for (int i = 0; i<letters.size(); i++){
            while( num >= vals[i]){
                
                num -=vals[i];
                
                ans+=letters[i];
            }
        }
        
        return ans;
    }
};