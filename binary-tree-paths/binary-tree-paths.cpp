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
    
    vector<string> helper(TreeNode* root, string s){
        vector<string> ans;
        if(!root) return ans;
        
        
        // char num = root->val + '0';
        // string curS = "->";
        // curS.push_back(num);
        s.append("->" + to_string(root->val));
        
        if(!root->left&&!root->right){
            ans.push_back(s.substr(2));
            return ans;
        }
        
        vector<string> l = helper(root->left, s);
        vector<string> r = helper(root->right, s);
        
        ans.insert(ans.end(), l.begin(), l.end());
        ans.insert(ans.end(), r.begin(), r.end());
        
        
        return ans;
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        
        string s="";
        
        return helper(root, s);
    }
};