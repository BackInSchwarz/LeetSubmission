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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL) return ans;
        //root
        ans.push_back(root->val);
        vector<int> l = preorderTraversal(root->left);
        vector<int> r = preorderTraversal(root->right);
        
        for (int i = 0; i <l.size();i++){
            ans.push_back(l[i]);
        }
        
        for (int i = 0; i <r.size();i++){
            ans.push_back(r[i]);
        }
        
        return ans;
        
    }
};
//preorder traverse means root left and right
    //end condition: root == NULL, return NULL. 
    //initial condition==general condition
    //