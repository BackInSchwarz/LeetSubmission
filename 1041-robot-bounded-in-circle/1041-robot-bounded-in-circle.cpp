class Solution {
public:
    bool isRobotBounded(string instructions) {
        int direct = 0;
        vector<int> xMove = {0, 1, 0, -1};
        vector<int> yMove = {1, 0, -1, 0};
        
        int x = 0;
        int y = 0;
        
        for (int i = 0; i< instructions.length(); i++){
            char s = instructions[i];
            if (s == 'G'){
                x += xMove[direct];
                y += yMove[direct];
            }
            
            if (s == 'L') direct -=1;
            if (s == 'R') direct +=1;
            
            direct = direct%4;
            if (direct<0) direct+=4;
            // cout<<"direct is :"<< direct<< endl;
        }
        
        if ((x==0 && y==0) ||( direct!=0))
            return true;
        
        return false;
        
    }
};

