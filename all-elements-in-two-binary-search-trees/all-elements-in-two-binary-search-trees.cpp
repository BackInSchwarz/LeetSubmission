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
    
    vector<int> BST2Vec(TreeNode* root){
        vector<int> ans;
        if (!root) return ans;
        vector<int> l = BST2Vec(root->left);
        vector<int> r = BST2Vec(root->right);
        
        for (int i = 0; i<l.size(); i++){
            ans.push_back(l[i]);
        }
        
        ans.push_back(root->val);
        
        for (int i = 0; i<r.size(); i++){
            ans.push_back(r[i]);
        }
        
        return ans;
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        vector<int> list1 = BST2Vec(root1);
        vector<int> list2 = BST2Vec(root2);
        
        vector<int> ans = list1;
        ans.insert(ans.end(), list2.begin(), list2.end());
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};