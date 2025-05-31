class Solution {
  public:
    void KahnsAlgo(unordered_map<int, vector<int>> &adj, vector<int> inDegree, queue<int>& que, vector<int>& topoBFS){
        // When queue gets emptied, it means that the graph is traversed completely that was possible
        while(!que.empty()){
            int u = que.front();
            que.pop();
            topoBFS.push_back(u);
            
            // Decrement inDegree of neighbors of 'u'
            for(int &v : adj[u]){
                inDegree[v]--;
                
                // If after decrementing, indegree becomes 0, push it into the queue
                if(inDegree[v] == 0){
                    que.push(v);
                }
            }
        }
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        
        for(vector<int> vec : edges){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
        }
        
        // Populate Indegree
        vector<int> inDegree(V, 0);
        for(pair<int, vector<int>> i : adj){
            vector<int> u = i.second;
            for(int v : u){
                inDegree[v]++;
            }
        }
        
        // Push nodes having indegree = 0 into the queue
        queue<int> que;
        for(int i=0; i<V; i++){
            if(inDegree[i] == 0){
                que.push(i);
            }
        }
        
        // topoBFS stores the final topological order using BFS
        vector<int> topoBFS;
        KahnsAlgo(adj, inDegree, que, topoBFS);
        
        return topoBFS;
    }
};
