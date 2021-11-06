class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int oStart = INT_MAX;
        int oEnd = INT_MAX;
        int ans = 0;
        for (auto point:points){
            //there no overlap or first case
            if ((oStart==INT_MAX&&oStart==oEnd)|| (oEnd<point[0])){
                //intialize overlapped area 
                oStart = point[0];
                oEnd = point[1];
                ans+=1;
            }else{
            //there is overlap
                //update the overlapped area. 
                oEnd = min(oEnd, point[1]);
            }
                


        }
        
        return ans;
    }
};