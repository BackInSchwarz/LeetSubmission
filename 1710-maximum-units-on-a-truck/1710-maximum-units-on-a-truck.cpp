class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        //box[i][0] number of box i
        //box[i][1] score of box i
        // vector<pair<int, int>> log;
        
        sort(boxTypes.begin(), boxTypes.end(), [&](auto& a, auto& b) {
            return a[1]>b[1];
        });
        
        int curCnt = 0;
        int ans = 0;
        
        for ( int i = 0; i < boxTypes.size(); i++){
            if ( ( curCnt + boxTypes[i][0] ) <= truckSize ){
                ans += boxTypes[i][0] * boxTypes[i][1] ;
                curCnt += boxTypes[i][0];
            }else{
                ans += (truckSize - curCnt) * boxTypes[i][1] ;
                curCnt = truckSize;
            }
            
            if (curCnt == truckSize) break;
        }
        
        return ans;
    }
};