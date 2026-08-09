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
    unordered_map<int, Node*> map;
    Node* cloneGraph(Node* node) {
        
        if(!node) return nullptr;
        int val = node->val;
        if(map.count(val)) return map[val];

        Node* newNode = new Node(val);
        map[val] = newNode;

        for(auto next : node->neighbors){
            newNode->neighbors.push_back(cloneGraph(next));
        } 
        return newNode;
    }
};