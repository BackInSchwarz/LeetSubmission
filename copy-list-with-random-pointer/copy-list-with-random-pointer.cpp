/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    map<Node*, Node*> ht;
    Node* helper(Node* root){
        if (root == NULL) return NULL;
        //not in table
        if (ht.find(root)!=ht.end()) return ht[root];
        
        ht[root] = new Node(root->val);
        ht[root]->next = helper(root->next);
        ht[root]->random = helper(root->random);
        
        return ht[root];
    }
    Node* copyRandomList(Node* head) {
        
        return helper(head);
    }
};