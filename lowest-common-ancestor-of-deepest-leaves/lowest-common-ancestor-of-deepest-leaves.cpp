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
    
    int dLeavesCnt;
    int depth;
    TreeNode* ans;
    
    int findDepth(TreeNode* root){
        if (!root) return 0;
        
        return max(findDepth(root->left), findDepth(root->right)) + 1;
    }
    
    void countDLeaves(TreeNode* root, int preLv){
        if (!root) return;
        
        if (!root->left && !root->right && (preLv+1) == depth)
            dLeavesCnt++;
        
        countDLeaves(root->left, preLv + 1);
        countDLeaves(root->right, preLv + 1);
        
        return;
    }
    
    int nLCA (TreeNode* root, int preLv){
        if (!root) return 0;
        
        int l = nLCA(root->left, preLv+1);
        int r = nLCA(root->right, preLv+1);
        int cur = ( (preLv+1) == depth );
        
        int curAns = l + r + cur;
        
        if ( !ans &&  curAns == dLeavesCnt){
            ans = root;
        }
        
        
        return curAns;
        
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        
        depth = findDepth(root);
        
        // cout<< "Depth is : "<< depth << endl;
        
        dLeavesCnt = 0;
        
        countDLeaves(root, 0);
        
        ans = NULL;
        
        nLCA(root, 0);
        
        
        return ans;
        
    }
};
