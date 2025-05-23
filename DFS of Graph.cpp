class Solution {
  public:
    void DFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<int>& DFSOrder){
        if(visited[u] == true){
            // cout<<"\n "<<u<<" is visited";
            return;
        }
        
        visited[u] = true;
        DFSOrder.push_back(u);
        // cout<<"\n "<<u<<" visited now";
        
        for(int &v : adj[u]){
            DFS(adj, v, visited, DFSOrder);
            // cout<<"\n "<<v<<" returned back";
        }
        
        // cout<<"\n "<<u<<" is over";
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        
        vector<bool> visited(V, false);
        vector<int> DFSOrder;
        
        DFS(adj, 0, visited, DFSOrder);
        
        return DFSOrder;
    }
};
