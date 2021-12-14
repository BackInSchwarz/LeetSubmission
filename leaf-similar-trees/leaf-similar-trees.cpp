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
    
    
    vector<int> findLeaf(TreeNode* root){
        vector<int> ans;
        if(!root) return ans;
        if(!root->left&&!root->right){
            ans.push_back(root->val);
            return ans;
        }
        
        vector<int> l = findLeaf(root->left);
        vector<int> r = findLeaf(root->right);
        
        if(l.size()==0) return r;
        if(r.size()==0) return l;
        
        ans.insert(ans.end(), l.begin(), l.end());
        ans.insert(ans.end(), r.begin(), r.end());
        
        return ans;
        
        
    }
    
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaves1 = findLeaf(root1);
        vector<int> leaves2 = findLeaf(root2);
        
        int n1 = leaves1.size();
        int n2 = leaves2.size();
        if(n1 != n2) return false;
        for(int i = 0; i < n1; i++){
            if (leaves1[i] != leaves2[i]) return false;
        }
        
        
        return true;
    }
};