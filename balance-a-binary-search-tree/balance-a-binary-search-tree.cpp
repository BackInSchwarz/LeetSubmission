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
    
    int findDepth(TreeNode* root){
        
        if (!root) return 0;
        
        return 1 + max( findDepth(root->left), findDepth(root->right) );
    }
    
    bool isBalanced(TreeNode* root){
        
        int l = findDepth(root->left);
        int r = findDepth(root->right);
        
        return abs(l-r)>1?false:true;
    }
    
    vector<int> BSTtoVector(TreeNode* root){
        vector<int> ans;
        
        if (!root) return ans;
        
        vector<int> l = BSTtoVector(root->left);
        vector<int> r = BSTtoVector(root->right);
        
        for ( int i = 0; i<l.size(); i++){
            ans.push_back(l[i]);
        }
        
        ans.push_back(root->val);
        
        for ( int i = 0; i<r.size(); i++){
            ans.push_back(r[i]);
        }
        
        return ans;
    }
    
    TreeNode* vector2BST(vector<int> & nums, int start, int end){
        
        int n = end-start;
        
        if (n<=0) return NULL;
        
        int rootInd = start + n/2;
        
        TreeNode* root = new TreeNode(nums[rootInd]);
        
        root->left = vector2BST( nums, start, rootInd);
        root->right = vector2BST ( nums, rootInd+1, end);
        
        return root;
    }
    
    
    TreeNode* balanceBST(TreeNode* root) {
        
        // if (isBalanced(root)) return root;
        
        vector<int> nums = BSTtoVector(root);
        
        for (auto num: nums)
            cout<<num<<endl;
        
        return vector2BST(nums, 0, nums.size());
    }
};