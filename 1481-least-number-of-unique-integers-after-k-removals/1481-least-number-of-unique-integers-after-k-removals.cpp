class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> hm;
        
        for (int num:arr) hm[num]++;
        
        vector<int> cnts;
        
        for(auto [key, val]:hm){
            cnts.push_back(val);
        }
        
        sort(cnts.begin(), cnts.end());
        
        int total = cnts.size();
        
        for ( int i = 0; i < cnts.size(); i++){
            if ( cnts[i]<=k){
                total -=1;
                k-=cnts[i];
            }else{
                break;
            }
        }
        
        return total;
    }
};