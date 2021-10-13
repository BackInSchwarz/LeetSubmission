class Solution {
public:
    stack<int> stk;
    bool isOperand(string token){
        if (token.length()>1) return false;
        if (!((token[0]-'0')>=0 && (token[0]-'0')<=9))
            return true;
        else
            return false;
    }
    
    int Operate(string token, int a, int b){
        if (token[0]=='+') return a+b;
        if (token[0]=='-') return a-b;
        if (token[0]=='*') return a*b;
        if (token[0]=='/') return a/b;
        return 0;
    }
    
    int parseNum(string token){
        int ans=0;
        int mut = 1;
        if (token[0]=='-'){
            for (int i = 0; i<token.length()-1;i++){
                ans += (token[token.length()-1-i]-'0')* mut;
                mut *=10;
            }
            ans*=-1;
        }else{
            for (int i = 0; i<token.length();i++){
                ans += (token[token.length()-1-i]-'0')* mut;
                mut *=10;
            }
        }
        return ans;

    }
    
    int evalRPN(vector<string>& tokens) {
        for (auto token: tokens){
            if (isOperand(token)){
                int b = stk.top();
                stk.pop();
                int a = stk.top();
                stk.pop();
                a = Operate(token, a, b);
                stk.push(a);
            }else{
                stk.push(parseNum(token));
            }
        }
        
        return stk.top();
    }
};