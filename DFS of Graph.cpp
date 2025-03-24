class Solution {
  public:
    void dfs(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<int>& dfsTraversal){
        if(visited[u]) return;
        
        dfsTraversal.push_back(u);
        visited[u] = true;
        for(int v:adj[u]){
            if(visited[v] == false){
                dfs(adj, v, visited, dfsTraversal);
            }
        }
    }
    
    
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> dfsTraversal;
        dfs(adj, 0, visited, dfsTraversal);
        return dfsTraversal;
    }
};
