class Solution {
public:
//     void helper(vector<vector<int>> &ans,vector<int> & curans, int remain, int n ){
//         // cout<<remain<<" "<<n<<endl;
//         if (n==1){
//             if (1<=remain && remain<=6){
//                 curans.push_back(remain);
//                 ans.push_back(curans);
//             }
//             return;
//         }
        
//         if (remain<n) return;
//         if (ans.size()>0) return;
//         for (int i = 1; i<=6;i++){
//             // cout<<i<<endl;
//             curans.push_back(i);
//             helper(ans, curans, remain-i, n-1);
//             curans.pop_back();
//         }
//         // continue;
        
//     }
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        
        int m = rolls.size();
        int msum = 0;
        for (int roll:rolls){
            msum+=roll;
        }
        int remain = mean*(n+m)-msum;
        
        if (remain<n || remain>(n*6)) return {};
        
        int avg = remain/n;
        int extra = remain - avg*n;
        // cout<<n<<" "<<extra<<" "<< avg<<endl;
        vector<int> ans(n, avg);
        
        for(int i = 0; i<extra;i++){
            ans[i]+=1;
        }
        return ans;

    }
};