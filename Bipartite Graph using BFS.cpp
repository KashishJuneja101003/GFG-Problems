class Solution {
  public:
    bool BFS(unordered_map<int, vector<int>>& adj, int currNode, vector<int>& color){
        // que is used to keep track of neighbors of currNode
        queue<int> que;
        que.push(currNode);
        
        color[currNode] = 1;
        
        
        // Color the neighbors of currNode
        while(!que.empty()){
            int u = que.front();
            que.pop();
            
            
            for(int& v : adj[u]){
                // If color of neighbors is equal, return false
                if(color[u] == color[v]){
                    return false;
                }
                
                // If the node is unvisited, color it with currColor
                if(color[v] == 0){
                    color[v] = -color[u];
                    que.push(v);
                }
            }
        }
        
        // If the loop works successfully, that means, the graph is bipartite till this point
        // Thus, return true
        return true;
    }
    
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Creating adjacency list
        unordered_map<int, vector<int>> adj;
        for(auto vec : edges){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        // color vector keeps track of colors (0 => Initial; -1 => color 1; 1 => color 2)
        // color vector can also be used to keep track of visited (color[i] != 0) & unvisited nodes (color[i] == 0)
        vector<int> color(V, 0);
        
        
        for(int i=0; i<V; i++){
            // If the node is unvisited, call BFS
            if(color[i] == 0){
                // If BFS return false, the graph is not bipartite
                // Hence, return false
                if(!BFS(adj, i, color)){
                    return false;
                }
            }
        }
        
        // If the graph is bipartite, return true
        return true;
    }
};
