class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Dist vector stores the min distance
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        for(int i=1; i<=V-1; i++){
            for(auto& vec:edges){
                int u = vec[0];
                int v = vec[1];
                int wt = vec[2];
                
                // Relax edge (u,v)
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Detect -ve cycle
        for(auto& vec:edges){
                int u = vec[0];
                int v = vec[1];
                int wt = vec[2];
                
                // Relax edge (u,v)
                if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                    return {-1};
                }
        }
        
        return dist;
    }
};
