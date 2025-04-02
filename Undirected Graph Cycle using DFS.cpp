class Solution {
  public:
    bool DFS_Cycle_Check(vector<vector<int>>&adj, int u, vector<bool> &visited, int parent){
        visited[u] = true;
        for(int &v:adj[u]){
            if(v == parent) continue;
            if(visited[v] == true) return true;
            if(DFS_Cycle_Check(adj, v, visited, u)) return true;
        }
        return false;
    }
    
    bool isCycle(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<bool> visited(n, false);
        
        for(int i=0; i<n; i++){
            if(!visited[i] && DFS_Cycle_Check(adj, i, visited, -1)){
                return true;
            }
        }
        
        return false;
    }
};
