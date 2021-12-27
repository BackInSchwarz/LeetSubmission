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
    
    TreeNode* ans;
    
    int findDepth(TreeNode* root){
        if (!root) return 0;
        
        return 1 + max(findDepth(root->left), findDepth(root->right));
    }
    
    int countLeaves(TreeNode* root, int preDepth, int targetDepth){
        if (!root) return 0;
        
        int curDepth = preDepth + 1;
        
        if (!root->left && !root->right && curDepth == targetDepth)
            return 1;
        
        return countLeaves(root->left, curDepth, targetDepth) + countLeaves(root->right, curDepth, targetDepth);
    }
    
    
    int findLCAn( TreeNode* root, int preDepth, int targetCnt, int targetDepth){
        if (!root) return 0;
        
        int curDepth = preDepth + 1;
        
        int curCnt = 0;
        
        if (!root->left && !root->right && curDepth == targetDepth)
            curCnt++;
        
        int l = findLCAn(root->left, curDepth, targetCnt, targetDepth);
        int r = findLCAn(root->right, curDepth, targetCnt, targetDepth);
        
        int cntSum = l + r + curCnt;
        
        if (ans==NULL and cntSum == targetCnt){
            ans = root;
        }

        
        
        return cntSum;
    }
    
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        
        if (!root) return NULL;
        
        ans = NULL;
        
        int h = findDepth(root);
        
        int n = countLeaves(root, 0, h);
        
        findLCAn(root, 0, n, h);
            
        return ans;
    }
};

