/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    unordered_map<Node*, Node*> hm;
    Node* cloneTree(Node* root) {
        if (!root) return NULL;
        
        if (hm.find(root)!=hm.end()) return hm[root];
        
        Node* cloneNode = new Node(root->val);
        
        hm[root] = cloneNode;

        for (auto child: root->children){
             cloneNode->children.push_back(cloneTree(child));
        }
        
        return cloneNode;
        
    }
};