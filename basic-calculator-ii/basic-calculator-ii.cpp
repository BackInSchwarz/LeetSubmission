class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if (n == 0) return 0;
        
        
        stack<int> stk;
        
        char oper = '+';
        int curNum = 0;
        
        for (int i = 0 ; i < s.length(); i++){
            
            char curChar = s[i];
            
            if (isdigit(curChar))
                curNum = curNum * 10  + ( curChar - '0');
            
            if (!isdigit(curChar) && !iswspace(curChar) || i == (n - 1)){
                if (oper == '+')
                    stk.push(curNum);
                if (oper == '-')
                    stk.push(-curNum);
                if (oper == '/'){
                    int last = stk.top();
                    stk.pop();
                    stk.push(last/curNum);
                }
                
                if (oper == '*')
                {
                    int last = stk.top();
                    stk.pop();
                    stk.push(last * curNum);
                }
                
                curNum = 0;
                
                oper = curChar;
                    
                
            }
            
        }
        
        
        int ans = 0;
        while(!stk.empty()){
            ans += stk.top();
            stk.pop();
        }
        
        return ans;
    }
};