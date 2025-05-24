class Solution {
  public:
    bool detectCycleBFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, int parent){
        visited[u] = true;
        
        queue<pair<int, int>> node_parent;
        node_parent.push({u, parent});
        
        while(!node_parent.empty()){
            int n = node_parent.front().first;
            int p = node_parent.front().second;
            node_parent.pop();
            
            for(int &v : adj[n]){
                if(v == p){
                    continue;
                }
                
                if(visited[v] == true){
                    return true;
                }
                
                node_parent.push({v, n});
                visited[v] = true;
            }
        }
        
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
                if(detectCycleBFS(adj, i, visited, -1)){
                    return true;
                }
            }
        }
        
        return false;
    }
};
