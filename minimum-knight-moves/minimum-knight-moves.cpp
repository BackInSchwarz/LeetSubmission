class Solution {
public:
    int minKnightMoves(int x, int y) {
        
        queue<pair<pair<int, int>, int>> q;
        q.push({{0,0}, 0});
        set<pair<int, int>> visited;
        
        vector<vector<int>> directions = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {-1,2}, {1,2}, {1,-2}, {-1,-2}};
        visited.insert({0,0});
        
        x = abs(x);
        y = abs(y);
        while(!q.empty())
        {
            pair<pair<int, int>, int> curr = q.front();
            q.pop();
            
            int xVal = curr.first.first;
            int yVal = curr.first.second;
            int dist = curr.second;
            
            if(x == xVal && yVal == y)
                return dist;
            
            if (xVal < -2 ||yVal < -2) continue;
		    if (xVal > x+2 || yVal > y+2) continue;
            
            for(int k=0; k<directions.size(); k++)
            {
                int newXVal = xVal + directions[k][0];
                int newYVal = yVal + directions[k][1];
                
                if(visited.find({newXVal, newYVal}) == visited.end())
                {
                    visited.insert({newXVal, newYVal});
                    q.push({{newXVal, newYVal}, dist+1});
                }
            }
        }
        return 0;
    }
};