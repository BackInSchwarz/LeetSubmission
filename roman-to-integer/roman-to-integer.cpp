class Solution {
public:
    int romanToInt(string s) {
        map<char, int> tb;
        tb['I'] = 1;
        tb['V'] = 5;
        tb['X'] = 10;
        tb['L'] = 50;
        tb['C'] = 100;
        tb['D'] = 500;
        tb['M'] = 1000;
        int last = 0;
        int ans =0;
        for (char c:s){
            ans +=tb[c];
            if (last<tb[c])
                ans = ans - last*2;
            last = tb[c];
        }
        return ans;
    }
};