/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// class Solution {
// public:
//     map<Node*, Node*> oldToNew;
    
//     Node* clone(Node* node){
//         if (oldToNew.find(node)!=oldToNew.end()) return oldToNew[node];

//         Node co_node(node->val);
//         Node* copy = &co_node;
//         oldToNew[copy] = node;

//         for (Node* nei:node->neighbors){
//             copy->neighbors.push_back(clone(nei));
//         }
//         return copy;
//     }
    
//     Node* cloneGraph(Node* node) {
        
//         return clone(node);
//     }
// };

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        if (copies.find(node) == copies.end()) {
            copies[node] = new Node(node -> val, {});
            for (Node* neighbor : node -> neighbors) {
                copies[node] -> neighbors.push_back(cloneGraph(neighbor));
            }
        }
        return copies[node];
    }
private:
    unordered_map<Node*, Node*> copies;
};