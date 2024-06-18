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
    unordered_map<int,Node*> new_graph;
    Node* cloneGraph(Node* node) {
        if(node==nullptr){
            return nullptr;
        }
        Node* ans = new Node(1);
        func(ans,node);
        return ans;
    }

    void func(Node* new_node, Node* old_node){
        
        new_node->val = old_node->val;
        new_graph[new_node->val] = new_node;

        vector<Node*> old_n = old_node->neighbors;

        for(int i = 0; i < old_n.size(); i++){

            if(new_graph.find(old_n[i]->val)!=new_graph.end()){
                new_node->neighbors.push_back(new_graph[old_n[i]->val] );
            }
            else{
                Node* temp_node = new Node(-1);
                func(temp_node,old_n[i]);
                new_node->neighbors.push_back(temp_node);
            }
        }
    }
};
