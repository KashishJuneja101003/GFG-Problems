class Solution {
  public:
    
    void topoDFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, stack<int>& stk){
        visited[u] = true;
        for(int &v : adj[u]){
            if(!visited[v]) topoDFS(adj, v, visited, stk);
        }
        stk.push(u);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        stack<int> stk;
        
        for(int u = 0; u<V; u++){
            if(!visited[u]){
                topoDFS(adj, u, visited, stk);
            }
        }
        
        vector<int>topoAns;
        while(!stk.empty()){
            topoAns.push_back(stk.top());
            stk.pop();
        }
        
        return topoAns;
    }
};
