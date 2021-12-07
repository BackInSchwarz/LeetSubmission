class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> hm;
        for(auto const& item:time){
            hm[item%60]++;
            // cout<<item%60<<endl;
        }
        int ans=0;
        auto it = hm.begin();
        while(it!=hm.end()){
            int key = it->first;
            int val = it->second;
            // cout<<key<<' '<<val<<endl;
            if(key==0){
                 //update here val! 
                ans= ans+ val*(val-1)/2; 
            }else if(key==30){
                //update here val! 
                ans=ans+ val*(val-1)/2;
            }else{
                if(hm.find(60-key)!=hm.end()) {
                    ans = ans + val* hm[60-key];
                    hm[key]=0;
                    hm[60-key]=0;
                }

            }
            it++;
        }
        
        return ans;
    }
};