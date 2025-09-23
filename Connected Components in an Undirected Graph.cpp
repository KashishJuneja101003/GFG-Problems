
class Solution {
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        
        for(vector<int>& vec:edges){
            int u = vec[0];
            int v = vec[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false);
        vector<vector<int>> components;
        
        for(int i=0; i<V; i++){
            if(!visited[i]){
                vector<int> nodes;
                queue<int> q;
                
                q.push(i);
                visited[i] = true;
                
                while(!q.empty()){
                    int u = q.front();
                    nodes.push_back(u);
                    q.pop();
                        
                    for(int& v:adj[u]){
                        if(!visited[v]){
                            q.push(v);
                            visited[v] = true;
                        }
                    }
                }
            components.push_back(nodes);
            }
        }
        
        return components;
    }
};
