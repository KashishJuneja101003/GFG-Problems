class Solution {
  public:
    void BFS(vector<vector<int>> &adj, int u, vector<bool>& visited, vector<int>& BFSOrder){
        queue<int> q;
        
        q.push(u); 
        visited[u] = true;
        BFSOrder.push_back(u);
        // cout<<"\n "<<u<<" is pushed and visited";
        
        while(!q.empty()){
            int u = q.front(); 
            q.pop();
            
            // cout<<"\n u = "<<u;
            
            for(int &v : adj[u]){
                if(!visited[v]){
                    q.push(v); 
                    visited[v] = true;
                    BFSOrder.push_back(v);
                    // cout<<"\n "<<v<<" is pushed and visited";
                }
                // else {
                    // cout<<"\n "<<v<<" is already visited";
                // }
            }
            
            // cout<<"\n "<<u<<" is over";
        }
    }
  
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int V = adj.size();
        vector<bool> visited(V, false);
        vector<int> BFSOrder;
        
        BFS(adj, 0, visited, BFSOrder);
        
        return BFSOrder;
    }
};
