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
    
    TreeNode* helper( vector<int>& preorder, int start, int end){
        
        int n = end - start;
        // cout << "Current N is: "<< n <<endl;
        if ( n<=0 ) return NULL;
        
        TreeNode* root = new TreeNode(preorder[start]);
        
        if (n==1) return root;
        
        int lCnt = 0;
        int rCnt = 0;
        
        
        
        for (int i = start + 1; i<end; i++){
            if ( preorder[i] > preorder[start] ){
                rCnt++;
            }
            if ( preorder[i] < preorder[start] ){
                lCnt++;
            }
        }

//         cout << "current lCnt and RCnt is :" << lCnt << " " << rCnt << endl;
        
        root->left = NULL;
        root->right = NULL;
        
        if ( lCnt!=0 ) root->left = helper(preorder, start+1, start+1+lCnt);
        if ( rCnt!=0 ) root->right = helper(preorder, start+1+lCnt, start+1+lCnt+rCnt);
        
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        return helper(preorder, 0, preorder.size());
    }
};