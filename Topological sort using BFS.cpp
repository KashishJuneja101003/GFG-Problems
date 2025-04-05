// Kahn's Algorithm
class Solution {
  public:
  
    void topoSortBFS(unordered_map<int, vector<int>>& adj, vector<int>& inDegree, queue<int>& que, vector<int>& topoSequence){
        while(!que.empty()){
            int node = que.front();
            que.pop();
            
            // Adding a node with 0 inDegree in the topological sorted sequence
            topoSequence.push_back(node);
            
            // Decrementing all the nodes having the "node" as its pre-requisite
            for(int &v:adj[node]){
                inDegree[v]--;
                
                // If inDegree of v becomes 0 after decrementing, push it into the queue
                if(inDegree[v] == 0){
                    que.push(v);
                }
            }
        }
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Making adjacency list
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        // inDegree array represents the indegree of all the nodes
        vector<int> inDegree(V, 0);
        for(int i=0; i<V; i++){
            for(int& v:adj[i]){
                inDegree[v]++;
            }
        }
        
        // Fill the queue with nodes having inDegree = 0
        queue<int> que;
        for(int i=0; i<V; i++){
            if(inDegree[i] == 0) que.push(i);
        }
        
        vector<int> topoSequence;
        
        topoSortBFS(adj, inDegree, que, topoSequence);
        
        return topoSequence;
    }
};
