class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> hm1;
        map<char, int> hm2;
        sort(s1.begin(),s1.end());
        for(auto c:s1) hm1[c]++;
        for(auto c:s2) hm2[c]++;
        
        for(auto const&[key,value]:hm1){
            if(hm2[key]<value) return false;
        }
        for(int i =0;i<s2.length();i++){
            if(hm1[s2[i]]==0) continue;
            // map<char, int> hm3;
            string curstr = s2.substr(i,s1.length());
            // if ()
            // cout<<curstr<<endl;
            sort(curstr.begin(), curstr.end());
            if(curstr.compare(s1)==0) return true;

        }
        
        return false;
    }
};