class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<char,int>> v;
        char cache = s[0]; int cacheCount = 1;
        for(int i = 1; i < s.length(); i++){
            if(s[i] != cache){
                v.push_back({cache, cacheCount});
                cache = s[i];
                cacheCount = 1;
            }
            else cacheCount++;
        }
        v.push_back({cache, cacheCount});

        int res = 0;
        for(auto word : words){
            int k = 0;
            word = word + 'X';
            char cache = word[0]; int cacheCount = 1;
            for(int i = 1; i < word.length(); i++){
                if(k == v.size()){
                    res--;
                    break;
                }
                if(word[i] != cache){
                    auto p = v[k];
                    if((p.first != cache) || (p.second < cacheCount) || (p.second > cacheCount && p.second < 3)) break;
                    k++;
                    cache = word[i];
                    cacheCount = 1;
                }
                else cacheCount++;
            }
            if(k == v.size()) res++;
        }
        return res;
    }
};