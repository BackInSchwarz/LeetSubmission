/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void helper(TreeNode* root, vector<pair<int, double>> & ans_ds, int lv){
        if(!root) return;
        int n = ans_ds.size();
        if(lv>n) {
            ans_ds.push_back({1, root->val});
            // cout<<lv<<" "<<ans_ds[lv-1].second<<" "<<root->val<<" "<<endl;
        }else{
            int cnt = ans_ds[lv-1].first;
            double avg = ans_ds[lv-1].second;
            ans_ds[lv-1].second = (avg*cnt+(root->val))/(cnt+1.0);
            // cout<<(avg+root->val)<<" "<<(cnt+1.0)<<endl;
            // cout<<lv<<" "<<ans_ds[lv-1].second<<" "<<root->val<<" "<<cnt<<endl;
            ans_ds[lv-1].first = cnt+1; 
        }
        
        helper(root->left, ans_ds, lv + 1);
        helper(root->right, ans_ds, lv + 1);
        
        return;
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        vector<pair<int, double>> ans_ds;
        
        helper(root, ans_ds, 1);
        
        vector<double> ans;
        for(auto item: ans_ds){
            ans.push_back(item.second);
        }
        
        return ans;
        
    }
};