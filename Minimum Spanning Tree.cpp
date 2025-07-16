class Solution {
  public:
    typedef pair<int, int> P;
    int spanningTree(int V, vector<vector<int>> adj[]) {
        vector<bool> visited(V, false);
        
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({0, 0});
        
        int sum = 0;
        
        while(!pq.empty()){
            int wt = pq.top().first;
            int u = pq.top().second;
            pq.pop();
            
            if(!visited[u]){
                sum += wt;
                visited[u] = true;
            }
            
            // Push neighbours if not visited
            for(auto& vec : adj[u]){
                int neighbour = vec[0];
                int neighbourWt = vec[1];
                
                if(!visited[neighbour]){
                    pq.push({neighbourWt, neighbour});
                }
            }
        }
        
        return sum;
    }
};
