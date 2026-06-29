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
    Node* solve(Node* node, unordered_map<Node*, Node*> &mp){
        if(mp.find(node)!=mp.end()){
            return mp[node];
        }
        Node* root = new Node(node->val);
        mp[node] = root;
        for(int i=0; i<node->neighbors.size(); i++){
            root->neighbors.push_back(solve(node->neighbors[i], mp));
        }
        return root;
    }
    Node* cloneGraph(Node* node) {
        if(!node) {
            return nullptr;
        }
        unordered_map<Node*, Node*> mp;
        return solve(node, mp);
    }
};
