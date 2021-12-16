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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;

        if (n%2==0) return ans;
        
        TreeNode* root= new TreeNode(0);
        if (n==1){
            ans.push_back(root);
            return ans;
        }
        
        int k = n - 1; // k is an even number
        for (int i = 1; i < k ; i++){
            if (i%2==0) continue;
            
            for (auto l:allPossibleFBT(i)){
                for (auto r:allPossibleFBT(k-i)){
                    TreeNode* curNode = new TreeNode(0);
                    curNode->left = l;
                    curNode->right = r;
                    
                    ans.push_back(curNode);
                }
            }
        }
        
        return ans;
    }
};