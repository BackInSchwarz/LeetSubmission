class Solution {
public:
    int minSwaps(vector<int>& data) {
        int oneLen = 0;
        for (auto it:data)
            if (it == 1)
                oneLen++;
        
        int curOneCnt = 0;
        int maxOneCnt = 0;
        
        for ( int i = 0; i<oneLen ; i++){
            if (data[i] == 1)
                curOneCnt++;
        }
        
        maxOneCnt = max( maxOneCnt, curOneCnt);
        
        for ( int i = oneLen; i<data.size(); i++){
            if ( data[i] == 1)
                curOneCnt++;
            if ( data[i - oneLen] == 1)
                curOneCnt--;
            
            maxOneCnt = max( maxOneCnt, curOneCnt);
        }
        
        return oneLen - maxOneCnt;
    }
};