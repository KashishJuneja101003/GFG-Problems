class Solution {
  public:
    void calcDFS(vector<vector<int>>& adj, vector<int>& order, vector<bool>& visited, int u){
        visited[u] = true;
        order.push_back(u);
        
        for(int& v:adj[u]){
            if(!visited[v]){
                calcDFS(adj, order, visited, v);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> order;
        vector<bool> visited(adj.size(), false);
        calcDFS(adj, order, visited, 0);
        return order;
    }
};
