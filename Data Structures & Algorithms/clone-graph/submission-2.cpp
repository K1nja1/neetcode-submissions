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
    Node* cloneGraph(Node* node) {
        if (node == nullptr) return nullptr;

        queue<Node*> q;
        unordered_map<Node*,Node*> visited;
        q.push(node);
        visited[node]=new Node(node->val);
        while(!q.empty()){
            Node* front=q.front();
            q.pop();
            for(auto it:front->neighbors){
                if(visited.count(it)==0){
                visited[it]=new Node(it->val);
                q.push(it);
                }

                visited[front]->neighbors.push_back(visited[it]);
            }
        }
        return visited[node];
    }
};
