class Solution {
  public:
    bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool> &inRecursion){
        visited[u] = inRecursion[u] = true;
        
        for(int &v : adj[u]){
            if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion))
                return true;
            else if (inRecursion[v] == true)
                return true;
        }
        
        inRecursion[u] = false;
        return false;
    }
    
    bool isCyclic(vector<vector<int>> &adj) {
        int V = adj.size();
        
        
        
        vector<bool> visited (V, false), inRecursion (V, false);
        
        for(int i=0; i<V; i++){
            if(!visited[i] && isCycleDFS(adj, i, visited, inRecursion)){
                return true;
            }
        }
        
        return false;
    }
};
