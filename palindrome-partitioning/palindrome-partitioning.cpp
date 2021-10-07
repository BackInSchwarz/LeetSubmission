// my solution: not good enough. need to use back tracking
// class Solution {
// public:
//     bool isPalindrome(string p){
//         int n = p.length();
//         for (int i = 0;i<n; i++){
//             if (p[i]!= p[n-1-i])
//                 return false;
//         }
//         return true;
//     }
//     vector<vector<string>> partition(string s) {
//         int n = s.length();
//         vector<vector<string>> ans;
//         map<vector<string>, int> hp;
//         for (int i=0;i<n; i++){
//             if (i==0){
//                 ans.push_back({s.substr(0,1)});
//                 continue;
//             }
//             int ansSize = ans.size();
//             for (int j=0;j<ansSize;j++){
//                 vector<string> curVec = ans[j];
//                 ans[j].push_back({s[i]});
//                 if (isPalindrome(curVec[curVec.size()-1]+s[i])==true){
//                     curVec[curVec.size()-1]+=s[i];
//                     ans.push_back(curVec);
//                     hp[curVec] = 1;
//                 }

//             }
//             if (i>1 && isPalindrome(s.substr(0,i+1))==true)
//                 if (hp.find({s.substr(0,i+1)})==hp.end())
//                     ans.push_back({s.substr(0,i+1)});
            
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> pars;
        vector<string> par;
        partition(s, 0, par, pars);
        return pars;
    }
private: 
    void partition(string& s, int start, vector<string>& par, vector<vector<string>>& pars) {
        int n = s.length();
        if (start == n) {
            pars.push_back(par);
        } else {
            for (int i = start; i < n; i++) {
                if (isPalindrome(s, start, i)) {
                    par.push_back(s.substr(start, i - start + 1));
                    partition(s, i + 1, par, pars);
                    par.pop_back();
                }
            }
        }
    }
    
    bool isPalindrome(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) {
                return false;
            }
        }
        return true;
    }
};