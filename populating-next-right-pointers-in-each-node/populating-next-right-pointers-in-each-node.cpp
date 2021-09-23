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
        if (root==NULL) return NULL;
        queue<Node*> q;
        q.push(root);
        
        while(!(q.empty())){
            Node* lastNode = NULL;
            int curSize = q.size();
            for (int i = 0; i< curSize; i++){
                //add nodes to queque;
                Node* curNode = q.front();
                if (curNode->left!=NULL){
                    q.push(curNode->left);
                    q.push(curNode->right);
                }
                //add link 
                if (i>0){
                    lastNode->next = curNode;
                }
                //pop and update last Node;
                lastNode = curNode;
                q.pop();
            }
        }
        return root;
    }
};