class Solution {
  public:
    void DFS(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, stack<int>& st){
        // Mark the current node as visited
        visited[u] = true;
        
        // Explore neighbors of current node
        // Push its children in stack
        for(int &v : adj[u]){
            if(!visited[v]) DFS(adj, v, visited, st);
        }
        
        // Push the current node, i.e., parent node
        st.push(u);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // Creating adjacency list
        unordered_map<int, vector<int>> adj;
        for(vector<int> vec : edges){
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
        }
        
        vector<bool> visited(V, false);
        stack<int> st;  // 'st' stores the topo order (parent above child)
        
        for(int i=0; i<V; i++){
            // Call DFS only when a node is not visited yet
            if(!visited[i]) DFS(adj, i, visited, st);
        }
        
        // Push the elements of stack into a topoOrder vector
        vector<int> topoOrder;
        while(!st.empty()){
            topoOrder.push_back(st.top());
            st.pop();
        }
        
        return topoOrder;
    }
};
