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
#include <stdbool.h>
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr){
            return nullptr;
        }
        queue<Node*> q;
        unordered_map<Node*, Node*> map; // Keeps track of the visited
        q.push(node);
        //map[node->val] = true;
        map[node]= new Node(node->val); // map to its clone
        //queue<Node*> q2;
       // q2.push(newHead);

        while(!q.empty() ){
     
            Node* currNode =  q.front();
            q.pop();

            for(auto neigh: currNode->neighbors){
                if(map.find(neigh) == map.end()){ // not cloned
                    map[neigh] = new Node(neigh->val);
                    q.push(neigh);
                }
                map[currNode]->neighbors.push_back(map[neigh]); // add to the cloned' neighbors
            }


        }
        return map[node];
    }


};