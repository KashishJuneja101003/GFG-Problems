class Solution {
  public:
    // Function to return the adjacency list for each vertex.
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        vector<vector<int>> adj(V);
        for(pair<int, int> p : edges){
            adj[p.first].push_back(p.second);
            adj[p.second].push_back(p.first);
        }
        return adj;
    }
};
