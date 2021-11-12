class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        vector<long> reachs(stations.size()+1,0);
        // vector<int> usedStation(stations.size()+1,-1);
        
        reachs[0] = startFuel;
        for (int i = 0;i<stations.size();i++){
            for(int j=i;j>=0;j--){
                if(reachs[j]>=stations[i][0]){
                    reachs[j+1] = max(reachs[j+1], reachs[j] + stations[i][1]);
                }
            }
        }
        // int ans = -1;
        for(int i=0;i<reachs.size();i++){
            cout<<reachs[i]<<endl;
            if (reachs[i]>=target) return i;
        }
        
        return -1;
    }
};