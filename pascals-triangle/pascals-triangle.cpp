class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> curLv;
        curLv.push_back(1);
        ans.push_back(curLv);
        if (numRows==1) return ans;
        curLv.push_back(1);
        ans.push_back(curLv);
        if (numRows==2) return ans;
        
        
        for (int i = 2;i<numRows;i++){
            curLv.push_back(1);
            for (int j=1;j<i;j++){
                curLv[j] = ans[i-1][j]+ ans[i-1][j-1];
            }
            
            ans.push_back(curLv);
                
        }
        
        return ans;
    }
};