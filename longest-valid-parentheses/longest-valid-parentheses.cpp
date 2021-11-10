class Solution {
public:
    int longestValidParentheses(string s) {
        // started at 7:45pm
        stack<char> mystackl;
        stack<char> mystackr;
        vector<int> valid(s.length(),1);
        // int ansl=0;
        // int curlen=0;
        for (int i = 0;i<s.length();i++){
            char c = s[i];
            if (c=='('){
                mystackl.push(c);
                // curlen+=1;
                // ans = max(ans, curlen);
            } 
            
            if (c==')'){
                if (mystackl.empty()){
                    // curlen=0;
                    valid[i]=0;
                }else{
                    mystackl.pop();
                    // curlen+=2;
                    // ansl = max(ansl,curlen);
                }
            }
        }
        // int ansr = 0;
        // curlen=0;
        for (int i = s.length()-1;i<s.length();i--){
            char c = s[i];
            if (c==')'){
                mystackr.push(c);
                // curlen+=1;
                // ans = max(ans, curlen);
            } 
            
            if (c=='('){
                if (mystackr.empty()){
                    // curlen=0;
                    valid[i]=0;
                }else{
                    mystackr.pop();
                    // curlen+=2;
                    // ansr = max(ansr,curlen);
                }
            }
        }
        int curLen =0;
        int ans = 0;
        for(auto num:valid){
            // cout<<num<<' ';
            if (num==1){
                curLen+=1;
                ans = max(ans,curLen);
            }else{
                curLen=0;
            }
        }
        
        return ans;
        
    }
};