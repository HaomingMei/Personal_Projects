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

class Solution {
public:
    unordered_map<Node*, Node*> map; // Tracks if Original Node has a Clone already
    Node* cloneGraph(Node* node) {
        if(node == nullptr){
            return nullptr; // Edge case
        }
        if(map.find(node) != map.end()){ // Case if the clone already exist
            return map[node]; // Return the clone if so
        }
        // Else, create the clone
        Node* curr = new Node(node->val); 
        map[node] = curr; // Map it

        for(auto neigh:node->neighbors){
            curr->neighbors.push_back(cloneGraph(neigh));
        }
        return curr; 
    }
};