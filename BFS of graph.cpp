class Solution {
  public:
    void BFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, vector<int>& result){
        queue<int> q;
        q.push(u);
        visited[u] = true;
        result.push_back(u);
        
        while(!q.empty()){
            int u = q.front();
            q.pop();
        
            for(int& v:adj[u]){
                if(!visited[v]){
                    q.push(v);
                    visited[v] = true;
                    result.push_back(v);
                }
            }
        }
    }
    
    vector<int> bfsOfGraph(vector<vector<int>> &mp) {
        unordered_map<int, vector<int>> adj;
        int V = mp.size();
        
        for(int i=0; i<V; i++){
            for(int v:mp[i]){
                adj[i].push_back(v);
            }
        }
        
        vector<bool> visited(V, false);
        vector<int> result;
        
        BFS(adj, 0, visited, result);
        return result;
    }
};
