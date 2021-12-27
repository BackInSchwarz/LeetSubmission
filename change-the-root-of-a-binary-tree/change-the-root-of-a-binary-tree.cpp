/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* flipBinaryTree(Node* root, Node * leaf) {
        
        if (root == leaf) return root;
        if (leaf == leaf -> parent->left){
            if(leaf->left) leaf->right = leaf->left;
            leaf->parent->left = NULL;
            leaf->left = flipBinaryTree(root, leaf->parent);
            leaf->left->parent = leaf;
        }
        else{
            if (leaf->left) leaf->right = leaf->left;
            leaf->parent->right = NULL;
            leaf->left = flipBinaryTree(root, leaf->parent);
            leaf->left->parent = leaf;
        }
        
        leaf->parent = NULL;
        
        return leaf;
    }
};