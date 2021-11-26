class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        // cout<<"start"<<endl;
        // for(auto plant:plants){
        //     cout<<plant<<endl;
        // }
        int n = plants.size();
        if (plants[n-1]==0) return 0;
    
        int steps=1;
        int curCap = capacity;
        for(int i=0;i<plants.size();i++){
            // if(plants[i]==0) continue;

            
            if (curCap>=plants[i]){
                curCap-=plants[i];
                plants[i]=0;
            }else{
                // int temp = plants[i];
                plants[i]-=curCap;
                curCap=0;
            }

            if ((i<n-1)&&(curCap<plants[i+1])) break;
            if ((i==(n-1))&&(plants[i]==0)) return steps;
            if (curCap==0) break;
            steps+=1;
        }
        
        // cout<<"current steps two way "<<2*steps<<endl;
        return 2*steps+ wateringPlants(plants, capacity);
        
    }
};