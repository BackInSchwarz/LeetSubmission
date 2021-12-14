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
    
    bool helper(TreeNode* root, unordered_map<int, int> & hm, int k){
        if (!root) return false;
        
        if(hm.find(k - (root->val)) != hm.end()) return true;
        
        hm[root->val]++;
        
        if ( helper(root->left, hm, k) ) return true;
        
        if ( helper(root->right, hm, k) ) return true;
        
        return false;
        
    }
    
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int, int> hm;
        return helper(root, hm, k);
    }
};