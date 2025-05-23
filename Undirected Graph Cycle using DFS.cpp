class Solution {
  public:
    bool detectCycleDFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, int parent){
        visited[u] = true;
        // cout<<"\n Visited Now: "<<u;
        
        for(int &v : adj[u]){
            // cout<<"\n Checking for node: "<<v;
            
            // Don't revisit the parent node
            if(v == parent){
                // cout<<"\n Parent Node: "<<v;
                continue;
            }
            
            // Cycle detected
            if(visited[v] == true){
                // cout<<"\n Node responsible for making cycle: "<<u;
                return true;
            }
            
            // Recurse, return if cycle detected at any point
            if(detectCycleDFS(adj, v, visited, u)){
                // cout<<"\n Cycle Detected (u, parent): "<<v <<", "<<u;
                return true;
            }
        }
        
        // No cycle found
        return false;
    }
  
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto vec : edges){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        
        // Check all components (graph might be disconnected)
        for(int i=0; i<V; i++){
            if(!visited[i]){
                // cout<<"\n Checking for node: "<<i;
                if(detectCycleDFS(adj, i, visited, -1)){
                    return true;
                }
            }
        }
        
        return false;
    }
};
