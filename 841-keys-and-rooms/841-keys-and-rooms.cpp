class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        stack<int> stk;
        stk.push(0);
        vector<int> v(rooms.size(), 0);
        
        while(!stk.empty()){
            int curRoom = stk.top();
            stk.pop();
            v[curRoom] = 1;
            
            for (int key:rooms[curRoom]){
                if (v[key] == 0)
                    stk.push(key);
            }
            
        }
        for (int i = 0; i<v.size(); i++){
            if (v[i] == 0)
                return false;
        }
        
        return true;
    }
};