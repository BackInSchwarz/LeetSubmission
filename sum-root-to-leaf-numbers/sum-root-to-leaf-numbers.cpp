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
    vector<vector<int>> helper(TreeNode* root){
        vector<vector<int>> ans;
        if (root==NULL) return ans;
        
        
        vector<vector<int>> l_ans = helper(root->left);
        vector<vector<int>> r_ans = helper(root->right);
        
        if (l_ans.size()==0 && r_ans.size()==0){
            ans.push_back({root->val});
            return ans;
        }
        
        if (r_ans.size()==0){
            for (int i = 0; i<l_ans.size();i++){
                l_ans[i].push_back(root->val);
            }
            return l_ans;
        }
        
        if (l_ans.size()==0){
            for (int i = 0; i<r_ans.size();i++){
                r_ans[i].push_back(root->val);
            }
            return r_ans;
        }
        
        for (int i = 0; i<l_ans.size();i++){
            l_ans[i].push_back(root->val);
        }
        
        for (int i = 0; i<r_ans.size();i++){
            r_ans[i].push_back(root->val);
            l_ans.push_back(r_ans[i]);
        }
        
        return l_ans;
    }
    int sumNumbers(TreeNode* root) {
        vector<vector<int>> ans = helper(root);
        long int sum=0;
        long mult = 1;
        for (int i =0; i <10;i++){
            for (int j=0;j<ans.size();j++){
                if (i<ans[j].size()){
                    cout<<ans[j][i]*mult<<endl;
                    sum += ans[j][i]*mult;
                }
            }
            mult = mult*10;
        }
        
        return sum;
    }
};