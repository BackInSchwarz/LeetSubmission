/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* lastN;
            int curSize = q.size();
            for (int i = 0; i < curSize; i++){
                Node* curNode = q.front();
                if (curNode->left != NULL) q.push(curNode->left);
                if (curNode->right != NULL) q.push(curNode->right);
                if (i>0){
                    lastN->next = curNode;
                }
                lastN = curNode;
                q.pop();
                
            }
        }
        return root;
    }
};