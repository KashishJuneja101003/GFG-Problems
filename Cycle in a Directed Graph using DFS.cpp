class Solution {
  public:
    bool detectCycleDFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion){
        // Mark node as visited
        visited[u] = true; inRecursion[u] = true;
        
        // Explore the neighbors of u
        for(int &v : adj[u]){
            // If the node 'v' is present in current recursion and visited again, it means a cycle is formed
            if(inRecursion[v] == true) return true;
            
            // If the subsequent recursion finds a cycle, true is returned
            // Calling detectCycleDFS function, only if the node is not visited earlier to avoid unnecessary recursive calls
            if(!visited[v] && detectCycleDFS(adj, v, visited, inRecursion)) return true;
        }
        
        // Mark the node as unvisited in inRecursion bcz it is no longer a part of the current recursion (going to occur next)
        inRecursion[u] = false;
        
        // If no cycle is detected, return false
        return false;
    }
  
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // Creating adjacency list
        unordered_map<int, vector<int>> adj;
        for(auto vec : edges){
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
        }
        
        // visited keeps track of visited nodes as a whole
        // inRecursion keeps track of the nodes visited in current recursion
        vector<bool> visited(V, false);
        vector<bool> inRecursion(V, false);
        
        // Calling DFS in a loop bcz the graph may be disconnected
        for(int i=0; i<V; i++){
            if(visited[i]) continue;
            if(detectCycleDFS(adj, i, visited, inRecursion)) return true;
        }
        
        return false;
    }
};
