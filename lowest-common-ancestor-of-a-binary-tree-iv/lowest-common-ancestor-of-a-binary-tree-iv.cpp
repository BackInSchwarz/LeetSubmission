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
    int helper(TreeNode* root, unordered_set <TreeNode*> &nodes_set, TreeNode* & ans){
        //NULL check
        if(!root) return 0;
        //self check
        int cnt_root =0;
        if(nodes_set.find(root)!=nodes_set.end()){
            cnt_root++;
        }
        //children check
        int left = helper(root->left, nodes_set, ans);
        int right = helper(root->right, nodes_set, ans);
        
        //find answer
//         if(cnt_root==0){
//             //case 3
//             if(left>0&&right>0&&((left+right)==nodes_set.size())){
//                 ans = root;
//             }
//         }else{
//             //cnt_root>0
//             //case 4
//             if(left>0&&right>0&&((left+right+cnt_root)==nodes_set.size())){
//                 ans = root;
//             }
//             // case 1
//             if(left>0&&(right==0)&&(left+cnt_root)==nodes_set.size()) ans = root;
//             //case 2
//             if(left==0&&right>0&&(right+cnt_root)==nodes_set.size()) ans = root;
               
//         }
        int total = cnt_root+left+right;
        if(ans==NULL&&(total==nodes_set.size())){
            ans = root;
        }
        
        
        // build answer
        return cnt_root+left+right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        //case 1: left + root and right ==0
        //case 2: right + root and left ==0
        //case 3: left + right and root==0
        //case 4: left + root + right. and they all greater>0
        if(nodes.size()==1) return nodes[0];
        
        TreeNode* ans=NULL;
        unordered_set <TreeNode*> nodes_set(nodes.begin(), nodes.end());
        helper(root, nodes_set, ans);
        
        return ans;
    }
};