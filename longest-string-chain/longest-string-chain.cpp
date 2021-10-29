class Solution {
public:
    
    
    bool isPred(string bigger, string shorter){
        if (bigger.length()-1!=shorter.length()) return false;
        
        int pointer = 0;
        for (char c:bigger){
            if (c==shorter[pointer]){
                pointer+=1;
            }
        }
        
        if (pointer == shorter.length()) return true;
        
        return false;
    }
    
    
    int longestStrChain(vector<string>& words) {
        map<int, vector<string>> dict;
        int maxLen = INT_MIN;
        for (auto const&word:words){
            dict[word.length()].push_back(word);
            maxLen = max(int(word.length()),maxLen);
        } 
        
        int ans = INT_MIN;
        map<string, int> dp;
        for (int i =0;i<dict[1].size();i++){
            dp[dict[1][i]] = 1;
            ans = max(ans, dp[dict[1][i]]);
        }

        for (int i = 2;i<=maxLen;i++){
            for (int j =0;j<dict[i].size();j++){
                // dict[i][j] - cur word
                dp[dict[i][j]] = 1;
                for (int k=0;k<dict[i-1].size();k++){
                    //dict[i-1][k] - last smaller word
                    if (isPred(dict[i][j], dict[i-1][k])){
                        dp[dict[i][j]] = max(dp[dict[i][j]], dp[dict[i-1][k]]+1);
                    }
                }
                ans = max(ans, dp[dict[i][j]]);
            }
        }
        
        // cout<<isPred("abc", "ab")<<endl;
        
        return ans;
    }
};