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
    unordered_map<TreeNode*, TreeNode*> parent;
    TreeNode* invalid;
    
    void helper(TreeNode* root, TreeNode* daddy){
        if (!root) return;
        
        //find the invalid;
        if (parent.find(root)!=parent.end()){
            invalid = parent[root];
            return;
        }
        
        parent[root] = daddy;
        
        helper(root->left, root);
        helper(root->right, root);
        
        return;
    }
    
    TreeNode* correctBinaryTree(TreeNode* root) {
        if (!root) return NULL;
        
        parent.clear();
        invalid = NULL;
        
        
        //traverse the tree and if any node has been traversed before, then its first parent is the bad guy.
        
        helper(root, NULL);
        
        //find the parent of the invalid node, cut it off
        TreeNode* invalidDaddy = parent[invalid];
        
        if ((invalidDaddy->left)==invalid) invalidDaddy->left = NULL;
        if ((invalidDaddy->right)==invalid) invalidDaddy->right = NULL;
        
        return root;
        
    }
};