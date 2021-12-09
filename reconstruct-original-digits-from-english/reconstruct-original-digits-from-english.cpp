class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> hm;
        for(char c:s){
            hm[c]++;
        }
        vector<int> cnt(10,0);
        cnt[0]= hm['z'];
        cnt[6]=hm['x'];
        cnt[2]=hm['w'];
        cnt[4]=hm['u'];
        cnt[8]=hm['g'];
        cnt[5]=hm['f']-cnt[4];
        cnt[3]=hm['h']-cnt[8];
        cnt[9]=hm['i']-cnt[8]-cnt[6]-cnt[5];
        cnt[1]=hm['o']-cnt[0]-cnt[2]-cnt[4];
        cnt[7]=hm['v']-cnt[5];
        string ans;
        for(int i=0;i<cnt.size();i++){
            for(int j=0;j<cnt[i];j++){
                ans.push_back('0'+i);
            }
        }
        
        return ans;

    }
};