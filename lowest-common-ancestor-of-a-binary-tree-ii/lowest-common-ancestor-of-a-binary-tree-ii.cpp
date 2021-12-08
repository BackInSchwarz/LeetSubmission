/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool left;
    bool right;
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return NULL;
        if(root==p){
            left = true;
            // cout<<"recursion"<<endl;
            // cout<<left<<endl;
            return root;
        } 
        if(root==q) {
            right = true;
            // cout<<"recursion"<<endl;
            // cout<<right<<endl;
            return root;
        }
        
        TreeNode* l = helper(root->left, p, q);
        TreeNode* r = helper(root->right, p, q);
        
        if(l&&r) return root;
        
        return l?l:r;
    }
    bool findNode(TreeNode* root, TreeNode* target){
        if(!root) return false;
        if(root==target) return true;
        auto l = findNode(root->left, target);
        auto r = findNode(root->right, target);
        return (l||r)?true:false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        TreeNode* ans = helper(root, p, q);
        // cout<<left<<endl;
        // cout<<right<<endl;
        left = findNode(root, p);
        right = findNode(root, q);
        
        return (left&&right)?ans:NULL;
    }
};