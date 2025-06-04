class Solution {
  public:
    bool DFS(unordered_map<int, vector<int>>& adj, int currNode, vector<int>& color, int currColor){
        color[currNode] = currColor;
        
        // Color the neighbors of currNode
        for(int& v : adj[currNode]){
            // If color of neighbors is equal, return false
            if(color[currNode] == color[v]){
                return false;
            }
            
            // If the node is unvisited, call DFS
            if(color[v] == 0){
                // Call the function after switching the color
                // If function returns false, return false
                if(!DFS(adj, v, color, currColor*(-1))){
                    return false;
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
        
        // currColor decides which color is to be painted for current node
        int currColor = 1;
        
        for(int i=0; i<V; i++){
            // If the node is unvisited, call DFS
            if(color[i] == 0){
                // If DFS return false, the graph is not bipartite
                // Hence, return false
                if(!DFS(adj, i, color, currColor)){
                    return false;
                }
            }
        }
        
        // If the graph is bipartite, return true
        return true;
    }
};
