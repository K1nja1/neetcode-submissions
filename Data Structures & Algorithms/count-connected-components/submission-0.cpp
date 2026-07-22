class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int count=0;
        vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                
                dfs(i,visited,adj);
                count++;
            }
        }
        return count;
        
    }
    void dfs(int curr,vector<bool> & visited, vector<vector<int>> &adj){
        visited[curr]=true;
        for(int it:adj[curr]){
            if(!visited[it]) dfs(it,visited,adj);
        }
    }
};
