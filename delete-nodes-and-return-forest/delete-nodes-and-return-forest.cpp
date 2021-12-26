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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        //how to delete to_delete children
        
        int n = to_delete.size();
        
        if (!root) return {};
        if (n == 0) return {root};

        
        stack<pair<TreeNode*, int>> mainStk; // 1 means parent is a target, 0 means parent is not a target.

        
        unordered_set<int> targets(to_delete.begin(), to_delete.end());
        
        // unordered_set<int> queued;
        
        vector<TreeNode*> ans;
        
        
        mainStk.push({root, 1});
        
        // queued.push(root->val);
        

        
        while(!mainStk.empty()){
            TreeNode* cur = mainStk.top().first;
            int isParentTarget = mainStk.top().second;
            mainStk.pop();
            
            int isCurTarget = (targets.find(cur->val) != targets.end());
            
            if (isParentTarget){
                // cur Node is not target
                if (!isCurTarget){
                    ans.push_back(cur);
                }
                // cur Node is target -> don't push to ans;
            }
            
            if (cur->left){
                
                mainStk.push({cur->left, isCurTarget});
                
                if (targets.find(cur->left->val)!=targets.end()){
                    cur->left = NULL;

                }
                
                

            }
            
            if (cur->right){
                
                mainStk.push({cur->right, isCurTarget});
                
                if (targets.find(cur->right->val)!=targets.end()){
                    cur->right = NULL;

                }
                

            }
            
        }
        
        return ans;
    }
};
