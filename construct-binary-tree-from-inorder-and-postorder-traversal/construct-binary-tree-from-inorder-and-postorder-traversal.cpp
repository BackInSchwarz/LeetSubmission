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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        //7:37
        //find the root. 
        
        if (inorder.size()==0) return NULL;
        if (postorder.size()==0) return NULL;
        
        int np = postorder.size();
        TreeNode * thisNode = new TreeNode();//C++ pointer what is the difference???
        thisNode->val = postorder[postorder.size()-1];
        
        if (postorder.size()==1) return thisNode;
        //create root node
        
        // root->val = rootVal;
        //find the left inorder. //c++ iterator
        int it = find(inorder.begin(), inorder.end(), postorder[postorder.size()-1]) - inorder.begin();// this is the end of the slice. 
        vector<int> inorderLeft(inorder.begin(), inorder.begin()+it);
        //left post order. pass them to a function 
        vector<int> postorderLeft(postorder.begin(), postorder.begin()+it);//c++ slicing
        
        //find the righ inorder
        vector<int> inorderRight(inorder.begin()+it+1, inorder.end()); //c++ slicing
        
        //right post order, 
        vector<int> postorderRight(postorder.begin()+it, postorder.end()-1);//c++ slicing
        
        
        thisNode->left = buildTree(inorderLeft, postorderLeft);
        thisNode->right = buildTree(inorderRight, postorderRight);
        
        return thisNode;
    }
};