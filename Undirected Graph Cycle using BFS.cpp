class Solution {
  public:
    bool isCycleBFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited){
        queue<pair<int, int>> que;
        
        que.push({u, -1});
        visited[u] = true;
        
        while(!que.empty()){
            auto P = que.front();
            que.pop();
            
            int src = P.first, parent = P.second;
            
            for(int &v : adj[src]){
                if(visited[v] == false){
                    visited[v] = true;
                    que.push({v, src});
                } else if(v != parent){
                    return true;
                }
            }
        }
        
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        vector<bool> visited(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i] && isCycleBFS(adj, i, visited)){
                return true;
            }
        }
        
        return false;
        
    }
};
