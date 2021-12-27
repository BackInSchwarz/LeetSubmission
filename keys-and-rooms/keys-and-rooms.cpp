class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        
        int n = rooms.size();
        
        vector<int> hasKey(n, 0);
        vector<int> opened(n, 0);
        // vector<int>
        
        stack<int> stk;
        
        stk.push(0);
        // queued[0]=1;
        hasKey[0]=1;
        // opened[0]=1;
        
        while(!stk.empty()){
            int curRoom = stk.top();
            stk.pop();
            
            if (hasKey[curRoom]) opened[curRoom]=1;
            
            if (opened[curRoom]){
                for (auto it: rooms[curRoom]){
                    if (opened[it]){
                        continue;   
                    }else{
                        hasKey[it]=1;
                        stk.push(it);
                    }
                }
            }
            
            if (stk.empty()){
                for (int i = 0; i<n ; i++){
                    if (hasKey[i]==1 && opened[i]==0)
                        stk.push(i);
                }
            }
        }
        
        for (int i =0; i<n;i++){
            if (opened[i]==0)
                return false;
        }
        
        return true;
        
    }
};