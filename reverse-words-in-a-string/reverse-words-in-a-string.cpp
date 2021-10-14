class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int lastSpace = -1;
        vector<string> ans;
        for (int i = 0; i < n; i++){
            if (s[i]==' ') continue;
            int curStart = i;
            while ((i+1)<n && s[i+1]!=' '){
                i++;
            }
            ans.push_back(s.substr(curStart, i - curStart + 1));
        }
        reverse(ans.begin(), ans.end());
        string ansstring;
        for (int i = 0; i<ans.size();i++){
            if (i == (ans.size()-1)){
                ansstring+=ans[i];
                continue;
            }
            ansstring+=ans[i]+' ';
        }
        
        return ansstring;
            
    }
};

// recursion
    // end case. no space. return as it is. 
    // general case: find the last space 
        //return the last word +" " + recursion(s.string(0, length of the previous charactors))