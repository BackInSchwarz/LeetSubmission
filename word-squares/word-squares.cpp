class Solution {
public:
    
    
    void helper(vector<vector<string>> &ans, vector<string>  curAns, map<string, vector<string>> &hm, int &n, vector<string>& words){
        if(curAns.size()==n){
            ans.push_back(curAns);
            return;
        }
        
        if(curAns.size()==0){
            for (auto word:words){
                curAns.push_back(word);
                helper(ans, curAns, hm, n, words);
                curAns.pop_back();
            }
        }else{
            int curLen = curAns.size();
            string curString="";
            for (int i=1;i<=curLen;i++){
                curString+=curAns[i-1][curLen];
            }
            for(auto curWord:hm[curString]){
                curAns.push_back(curWord);
                helper(ans, curAns, hm, n, words);
                curAns.pop_back();
            }
        }
        return;
        
    }
    
    vector<vector<string>> wordSquares(vector<string>& words) {
        //create the hashmap
        map<string, vector<string>> hm;
        int n = words[0].length();
        for(int i = 1;i<n;i++){
            for(auto word:words){
                hm[word.substr(0,i)].push_back(word);
            }
        }
        //create the answer loop. Becasue it has layers. It is better to use recursion. 
        
        vector<vector<string>> ans;
        helper(ans, {}, hm,n, words);
        
        return ans;
        
    }
};