/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    
    
    NodeCopy* helper(Node* root, unordered_map<Node*, NodeCopy*> & hm){
        if (!root) return NULL;
        
        if ( hm.find(root)!=hm.end() ) return hm[root];
        
        NodeCopy* newNode = new NodeCopy(root->val);
        
        hm[root] = newNode;
        
        newNode->random = helper(root->random, hm);
        newNode->left = helper(root->left, hm);
        newNode->right = helper(root->right, hm);
        

        
        return newNode;
        
    }
    
    NodeCopy* copyRandomBinaryTree(Node* root) {
        unordered_map<Node*, NodeCopy*> hm;
        
        return helper (root, hm);
        
    }
};