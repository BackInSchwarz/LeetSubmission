class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> curLv;
        curLv.push_back(1);
        if (rowIndex ==0) return curLv;
        
        curLv.push_back(1);
        if (rowIndex ==1) return curLv;
        
        vector<int> lastLv = curLv;
        for (int i =2;i<=rowIndex;i++){
            curLv.push_back(1);
            for (int j = 1;j<i;j++){
                curLv[j] = lastLv[j] + lastLv[j-1];
            }
            lastLv = curLv;
        }
        
        return curLv;
    }
};