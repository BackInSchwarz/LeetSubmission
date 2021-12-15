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
    TreeNode* helper(vector<int>& nums, int start, int end) {
        
        if ( start >= end ) return NULL;
        
        int curMax = INT_MIN;
        int curMaxInd = 0;
        
        for (int i = start ; i < end; i++){
            if ( nums[i] > curMax ){
                curMax = nums[i];
                curMaxInd = i;
            }
        }
        
        TreeNode * root = new TreeNode(curMax);
        
        root->left = helper( nums, start, curMaxInd);
        root->right = helper( nums, curMaxInd+1, end);    
        
        return root; 
    }
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(nums, 0, nums.size());
    }
};