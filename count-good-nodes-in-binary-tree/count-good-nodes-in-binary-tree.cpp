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
    int cnt;
    
//     int BranchWithSmallestMaxDesc(TreeNode* root){
//         // if (!root) 
        
//         if (!root->left&&!root->right) return root->val;
//         int l = INT_MAX;
//         int r = INT_MAX;
//         if (root->left) 
//             l = BranchWithSmallestMaxDesc(root->left);
//         if (root->right) 
//             r = BranchWithSmallestMaxDesc(root->right);
        
//         if ((l!=INT_MAX)&&(l<=(root->val)) || (r!=INT_MAX)&&(r<=(root->val))){
//             cnt++;
//         }

//         cout<< "cur Node is : "<< root->val << " min Branch is : "<< min(l, r)<<endl;
//         return max( root->val, min( l, r));
        
//     }
    
    void helper(TreeNode* root, int maxAncestor){
        if (!root) return;
        
        if (root->val>=maxAncestor){
            cnt++;
            maxAncestor = root->val;
        }

        
        helper(root->left, maxAncestor);
        helper(root->right, maxAncestor);
        
        return;
    }
    
    int goodNodes(TreeNode* root) {
        cnt = 0;
        
        helper(root, INT_MIN);
        
        return cnt;
    }
};